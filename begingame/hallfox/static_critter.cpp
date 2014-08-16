//Static Critter
//Demonstrates static member variables and functions

#include <iostream>

using namespace std;

class Critter
{
public:
    static int Total;
    
    Critter(int h=0);
    static int GetTotal();

private:
    int hunger;
};
int Critter::Total = 0; // static member initialization
Critter::Critter(int h):
    hunger(h)
{
    cout << "A critter has been born!" << endl;
    Total++;
}
int Critter::GetTotal()
{
    return Total;
}

int main()
{
    cout << "The total number of critters is: ";
    cout << Critter::Total << "\n\n";

    Critter crit1, crit2, crit3;

    cout << "\nThe total number of critters is: ";
    cout << Critter::GetTotal() << "\n";

    return 0;
}
