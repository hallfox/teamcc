//Blackjack
//Plays a simple version of the casino game of blackjack; for 1- 7 players

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card
{
public:
    enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    Card(Rank r=ACE, Suit s=SPADES, bool ifu=true);

    int getValue() const;
    void flip();

    friend ostream& operator<<(ostream& os, const Card& card);

private:
    Rank rank;
    Suit suit;
    bool faceUp;
};

Card::Card(Rank r, Suit s, bool ifu):
    rank(r),
    suit(s),
    faceUp(ifu)
{}

int Card::getValue() const
{
    //if a card is face down, its value is 0
    int value = 0;
    if (faceUp)
    {
	value = rank;
	if (value > 10)
	{
	    value = 10;
	}
	return value;
    }
    return value;
}

void Card::flip()
{
    faceUp = !faceUp;
}

class Hand
{
public:
    Hand();
    virtual ~Hand();
    
    //adds a card to the hand
    void add(Card* pCard);
    //clears hand of cards
    void clear();
    //gets hand total value, treats aces as 1 or 11
    int getTotal() const;
    //gets size of hand
    int getSize() const;
    
protected:
    vector<Card*> cards;    
};

Hand::Hand()
{
    cards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

void Hand::add(Card* pCard)
{
    cards.push_back(pCard);
}

void Hand::clear()
{
    vector<Card*>::iterator iter = cards.begin();
    for (iter = cards.begin(); iter != cards.end(); iter++)
    {
	delete *iter;
	*iter = 0;
    }
    cards.clear();
}

int Hand::getTotal() const
{
    if(cards.empty())
    {
	return 0;
    }	    
    if(cards[0]->getValue() == 0)
    {
	return 0;
    }

    vector<Card*>::const_iterator iter = cards.begin();
    int total = 0;
    bool hasAce = false;
    for (iter = cards.begin(); iter != cards.end(); iter++)
    {
	total += (*iter)->getValue();
	if ((*iter)->getValue() == Card::ACE)
	{
	    hasAce = true;
	}
    }
    
    if (hasAce & total <= 11)
    {
	total+=10;
    }

    return total;
}

int Hand::getSize() const
{
    return cards.size();
}

class GenericPlayer: public Hand
{
public:
    GenericPlayer(const string& name="");
    virtual ~GenericPlayer();
    
    //indicates whether or not a generic player wants to keep hitting
    virtual bool isHitting() const = 0;
    
    //returns whether generic player has busted - has a total greater than 21
    bool isBusted() const;
    //announces that the generic player busts
    void bust() const;

    friend ostream& operator<<(ostream& os, const GenericPlayer& gp);
    

protected:
    string name;
};

GenericPlayer::GenericPlayer(const string& name):
    name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::isBusted() const
{
    return getTotal() > 21;
}

void GenericPlayer::bust() const
{
    cout << name << " busts.\n";
}

class Player: public GenericPlayer
{
public:
    Player(const string& name="");
    virtual ~Player();

    //returns whether or not the player wants another hit
    virtual bool isHitting() const;
    //announces the player wins
    void win() const;
    //announces that the player loses
    void lose() const;
    //announces that the player pushes
    void push() const;
};

Player::Player(const string& name): GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
    cout << name << ", do you want a hit? (y/n): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << name << " wins!\n";
}

void Player::lose() const
{
    cout << name << " loses.\n";
}

void Player::push() const
{
    cout << name << " pushes.\n";
}

class House: public GenericPlayer
{
public:
    House(const string& name="House");
    virtual ~House();
    
    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool isHitting() const;
    //flips over first card
    void flipFirstCard();
};

House::House(const string& name):
    GenericPlayer(name)
{}

House::~House()
{}

bool House::isHitting() const
{
    return (getTotal() <= 16);
}

void House::flipFirstCard()
{
    if (!cards.empty())
    {
	cards[0]->flip();
    }
    else
    {
	cout << "No card to flip!\n";
    }
}

class Deck: public Hand
{
public:
    Deck();
    virtual ~Deck();

    //create a standard deck of 52 cards
    void populate();
    //shuffle cards
    void shuffle();
    //deal one card to a hand
    void deal(Hand& hand);
    //give additional cards to a generic player
    void additionalCards(GenericPlayer& gp);
};

Deck::Deck()
{
    cards.reserve(52);
    populate();
}

Deck::~Deck(){}

void Deck::populate()
{
    for (int s = Card::CLUBS; s <= Card::SPADES; s++)
    {
	for (int r = Card::ACE; r <= Card::KING; r++)
	{
	    add(new Card(static_cast<Card::Rank>(r),
			 static_cast<Card::Suit>(s)));
	}
    }
}

void Deck::shuffle()
{
    random_shuffle(cards.begin(), cards.end());
}

void Deck::deal(Hand& hand)
{
    if (!cards.empty())
    {
	hand.add(cards.back());
	cards.pop_back();
    }
    else
    {
	cout << "Out of cards. Unable to deal.";
    }
}

void Deck::additionalCards(GenericPlayer& gp)
{
    cout << endl;
    //continue to deal a card as long as generic player isn't busted and
    //wants another hit
    while (!gp.isBusted()) //weird no short-circuit issue
    {
	if (gp.isHitting())
	{
	    deal(gp);
	    cout << gp << endl;
	    if (gp.isBusted())
	    {
		gp.bust();
	    }
	}
	else
	{
	    break;
	}
    }
}

class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    //plays the game of blackjack
    void play();
    
private:
    Deck deck;
    House house;
    vector<Player> players;
};

Game::Game(const vector<string>& names)
{
    //create a vector of players from a vector of names
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); pName++)
    {
	players.push_back(Player(*pName));
    }

    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    deck.populate();
    deck.shuffle();
}

Game::~Game(){}

void Game::play()
{
    if (deck.getSize() < 10)
    {
	deck.clear();
	deck.populate();
	deck.shuffle();
    }

    //deal initial 2 cards to everyone
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; i++)
    {
	for (pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
	{
	    deck.deal(*pPlayer);
	}
	deck.deal(house);
    }

    //hide house's first card
    house.flipFirstCard();

    //display everyone's hand
    for (pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
    {
	cout << *pPlayer << endl;
    }
    cout << house << endl;

    //deal additional cards to players
    for (pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
    {
	deck.additionalCards(*pPlayer);
    }

    //reveal house's first card
    house.flipFirstCard();
    cout << endl << house;

    //deal additional cards to house
    deck.additionalCards(house);

    if(house.isBusted())
    {
	//everyone still playing wins
	for (pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
	{
	    if (!pPlayer->isBusted())
	    {
		pPlayer->win();
	    }
	}
    }
    else
    {
	//compare each player still playing to house
	for (pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
	{
	    if (!pPlayer->isBusted())
	    {
		if (pPlayer->getTotal() > house.getTotal())
		{
		    pPlayer->win();
		}
		else if (pPlayer->getTotal() < house.getTotal())
		{
		    pPlayer->lose();
		}
		else
		{
		    pPlayer->push();
		}
	    }
	}
    }

    //remove everyone's cards
    for (pPlayer = players.begin(); pPlayer != players.end(); pPlayer++)
    {
	pPlayer->clear();
    }
    house.clear();
}

//function prototypes
ostream& operator<<(ostream& os, const Card& card);
ostream& operator<<(ostream& os, const GenericPlayer& gp);

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";
    
    int numPlayers = 0;
    while(numPlayers < 1 || numPlayers > 7)
    {
	cout << "How many players? (1 - 7): ";
	cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; i++)
    {
	cout << "Enter player name: ";
	cin >> name;
	names.push_back(name);
    }
    cout << endl;
    
    //the game loop
    Game game(names);
    char again = 'y';

    while (again != 'n' & again != 'N')
    {
	game.play();
	cout << "\nDo you want to play again? (y/n): ";
	cin >> again;
    }

    return 0;
}

//overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& card)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", 
	    "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (card.faceUp)
    {
	os << RANKS[card.rank] << SUITS[card.suit];
    }
    else
    {
	os << "XX";
    }
    
    return os;
}

//overloads << operator so a GenericPlayer object can be sent to cout
ostream& operator<<(ostream& os, const GenericPlayer& gp)
{
    os << gp.name << ":\t";
    
    vector<Card*>::const_iterator pCard;
    if (!gp.cards.empty())
    {
	for (pCard = gp.cards.begin(); pCard != gp.cards.end(); pCard++)
	{
	    os << *(*pCard) << "\t";
	}

	if (gp.getTotal() != 0)
	{
	    cout << "(" << gp.getTotal() << ")";
	}
    }
    else
    {
	os << "<empty>";
    }

    return os;
}
