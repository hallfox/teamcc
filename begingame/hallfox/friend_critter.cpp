//Friend Critter
//Demonstrates friend functions and operator overloading

#include <iostream>
#include <string>

using namespace std;

class Critter
{
    //make following global functions friends of the Critter class
    friend void peek(const Critter& critter);
    friend ostream& operator<<(ostream& os, const Critter& critter);
    
public:
    Critter(const string& name="");
    
private:
    string name;
};

Critter::Critter(const string& name):
    name(name)
{}

void peek(const Critter& critter);
ostream& operator<<(ostream& os, const Critter& critter);

int main()
{
    Critter crit("Poochie");
    
    cout << "Calling peek() to access crit's private data member, name:\n";
    peek(crit);
    
    cout << "\nSending crit object to cout with the << operator:\n";
    cout << crit;

    return 0;
}

//global friend function which can access all of a Critter object's members
void peek(const Critter& critter)
{
    cout << critter.name << endl;
}

//global friend function which can access all of Critter object's members
//overloads the << operator so you can send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& critter)
{
    os << "Critter Object - ";
    os << "name: " << critter.name;
    return os;
}
