//Critter Caretaker

#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int h=0, int b=0);
    void talk();
    void eat(int food=4);
    void play(int fun=4);

private:
    int hunger;
    int boredom;
    int getMood() const;
    void passTime(int time=1);
};
Critter::Critter(int h, int b):
    hunger(h),
    boredom(b)
{}
inline int Critter::getMood() const
{
    return (hunger + boredom);
}
void Critter::passTime(int time)
{
    hunger += time;
    boredom += time;
}
void Critter::talk()
{
    cout << "I'm a critter and I feel ";
    
    int mood = getMood();
    if (mood > 15)
    {
	cout << "mad.\n";
    }
    else if (mood > 10)
    {
	cout << "frustrated.\n";
    }
    else if (mood  > 5)
    {
	cout << "okay.\n";
    }
    else
    {
	cout << "happy.\n";
    }
    
    passTime();
}
void Critter::eat(int food)
{
    cout << "Brruppp.\n";
    hunger -= food;
    if (hunger < 0)
    {
	hunger = 0;
    }

    passTime();
}
void Critter::play(int fun)
{
    cout << "Wheeee!\n";
    
    boredom -= fun;
    if (boredom < 0)
    {
	boredom = 0;
    }
    passTime();
}

int main()
{
    Critter crit;
    int choice;
    
    cout << "Welcome to Critter Caretaker!\n";

    do
    {
	cout << "\n0. Quit\n";
	cout << "1. Talk\n";
	cout << "2. Eat\n";
	cout << "3. Play\n";
	cout << "\nChoose what you want to do: ";
	cin >> choice;
	
	switch (choice)
	{
	case 0:
	    cout << "Good-bye.\n";
	    break;
	case 1:
	    crit.talk();
	    break;
	case 2:
	    crit.eat();
	    break;
	case 3:
	    crit.play();
	    break;
	default:
	    cout << "Sorry but " << choice << " is not a valid choice.";
	    break;
	}
    } while (choice != 0);

    return 0;
}
