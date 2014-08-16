//Critter Farm
//Demonstrates object containment

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter
{
public:
    Critter(const string& name="");
    string getName() const;

private:
    string name;
};
Critter::Critter(const string& name):
    name(name)
{}
inline string Critter::getName() const
{
    return name;
}

class Farm
{
public:
    Farm(int spaces=1);
    void add(const Critter& critter);
    void rollCall() const;

private:
    vector<Critter> critters;
};
Farm::Farm(int spaces)
{
    critters.reserve(spaces);
}
void Farm::add(const Critter& critter)
{
    critters.push_back(critter);
}
void Farm::rollCall() const
{
    for (vector<Critter>::const_iterator iter = critters.begin();
	 iter != critters.end();
	 iter++)
    {
	cout << iter->getName() << " here.\n";
    }
}

int main()
{
    Critter crit("Poochie");
    cout << "My critter's name is " << crit.getName() << endl;
    
    cout << "\nCreating critter farm.\n";
    Farm myFarm(3);
    
    cout << "\nAdding three critters to the farm.\n";
    myFarm.add(Critter("Moe"));
    myFarm.add(Critter("Larry"));
    myFarm.add(Critter("Curly"));
    
    cout << "\nCalling roll...\n";
    myFarm.rollCall();

    return 0;
}
