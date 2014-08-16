//Game Lobby
//Simulates a game lobby where players wait

#include <iostream>
#include <string>

using namespace std;

class Player
{
    friend ostream& operator<<(ostream& os, const Player& player);

public:
    Player(const string& name="");
    string getName() const;
    Player* getNext() const;
    void setNext(Player* next);

private:
    string name;
    Player* pNext;
};

Player::Player(const string& name):
    name(name),
    pNext(0)
{}

string Player::getName() const
{
    return name;
}

Player* Player::getNext() const
{
    return pNext;
}

void Player::setNext(Player* next)
{
    pNext = next;
}

ostream& operator<<(ostream& os, const Player& player)
{
    os << player.name;
}

class Lobby
{
    friend ostream& operator<<(ostream& os, const Lobby& lobby);
    
public:
    Lobby();
    ~Lobby();
    void addPlayer();
    void removePlayer();
    void clear();
    
private:
    Player* pHead;
    Player* pTail;
};

Lobby::Lobby():
    pHead(0),
    pTail(0)
{}

Lobby::~Lobby()
{
    clear();
}

void Lobby::addPlayer()
{
    //create a new player node
    cout << "Please enter the name of the new player: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);
    
    //if list is empty, make head of list this new player
    if (pHead == 0)
    {
	pHead = pNewPlayer;
    }
    //otherwise find the end of the list and add the player there
    else
    {
	pTail->setNext(pNewPlayer);
    }

    //always move the tail to the new player
    pTail = pNewPlayer;
}

void Lobby::removePlayer()
{
    if (pHead == 0)
    {
	cout << "The game lobby is empty. No one to remove!\n";
    }
    else
    {
	Player* pTemp = pHead;
	pHead = pHead->getNext();
	delete pTemp;
    }
}

void Lobby::clear()
{
    while(pHead != 0)
    {
	removePlayer();
    }
}

ostream& operator<<(ostream& os, const Lobby& lobby)
{
    Player* pIter = lobby.pHead;
    
    os << "\nHere's who's in the game lobby:\n";
    if (pIter == 0)
    {
	os << "The lobby is empty.\n";
    }
    else
    {
	while (pIter != 0)
	{
	    os << *pIter << endl;
	    pIter = pIter->getNext();
	}
    }

    return os;
}

int main()
{
    Lobby lobby;
    int choice;
    
    do
    {
	cout << lobby;
	cout << "\nGAME LOBBY\n";
	cout <<"0 - Exit the program.\n";
	cout << "1 - Add a player to the lobby.\n";
	cout << "2 - Remove a player from the lobby.\n";
	cout << "3 - Clear the lobby.\n";
	cout << endl << "Enter choice: ";
	cin >> choice;

	switch(choice)
	{
	case 0:
	    cout << "Goodbye.\n";
	    break;
	case 1:
	    lobby.addPlayer();
	    break;
	case 2:
	    lobby.removePlayer();
	    break;
	case 3:
	    lobby.clear();
	    break;
	default:
	    cout << "That was not a valid choice.\n";
	}
    } while (choice != 0);

    return 0;
}
