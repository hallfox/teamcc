//Private Critter
//Demonstrates setting member access levels

#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger=0);
    int getHunger() const;
    void setHunger(int hunger);

private:
    int hunger;
};
Critter::Critter(int hunger):
    hunger(hunger) //it's possible, but I will refrain from doing this
{
    cout << "A new critter has been born!" << endl;
}
int Critter::getHunger() const
{
    return hunger;
}
void Critter::setHunger(int hunger)
{
    if (hunger < 0)
    {
	cout << "You can't set a critter's hunger to a negative number.\n\n";
    }
    else
    {
	this->hunger = hunger;
    }
}

int main()
{
    Critter crit(5);
    //cout << crit.hunger; //illegal, hunger is private

    cout << "Calling getHunger(): " << crit.getHunger() << "\n\n";

    cout << "Calling setHunger() with -1.\n";
    crit.setHunger(-1);
    
    cout << "Calling setHunger() with 9.\n";
    crit.setHunger(9);
    cout << "Calling getHunger(): " << crit.getHunger() << "\n\n";

    return 0;
}
