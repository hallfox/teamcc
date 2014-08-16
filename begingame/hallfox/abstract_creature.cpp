//Abstract Creature
//Demonstrates abstract classes

#include <iostream>

using namespace std;

class Creature //abstract
{
public:
    Creature(int health=100);
    virtual void greet() const = 0; //pure virtual member function
    virtual void displayHealth() const;

protected:
    int health;
};

Creature::Creature(int health):
    health(health)
{}

void Creature::displayHealth() const
{
    cout << "Health: " << health << endl;
}

class Orc: public Creature
{
public:
    Orc(int health=120);
    virtual void greet() const;
};

Orc::Orc(int health):
    Creature(health)
{}

void Orc::greet() const
{
    cout << "The orc grunts hello.\n";
}

class OrcBoss: public Orc
{
public:
    OrcBoss();
    virtual void greet() const;
};

OrcBoss::OrcBoss(): Orc(180) {}

void OrcBoss::greet() const
{
    cout << "The orc boss growls hello.\n";
}

int main()
{
    Creature* pCreature = new Orc();
    pCreature->greet();
    pCreature->displayHealth();
    delete pCreature;

    pCreature = new OrcBoss();
    pCreature->greet();
    pCreature->displayHealth();
    delete pCreature;
    
    pCreature = 0;

    return 0;
}
