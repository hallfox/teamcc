//Heap Data Member
//Demonstrates an object with a dynamically allocated data member

#include <iostream>
#include <string>

using namespace std;

class Critter
{
public:
    Critter(const string& name="", int age=0);
    ~Critter(); //desctructor prototype
    Critter(const Critter& c); //copy constructor prototype
    Critter& operator=(const Critter& c); //overloaded assignment op
    void greet() const;

private:
    string* pName;
    int age;
};

Critter::Critter(const string& name, int age)
{
    cout << "Constructor called\n";
    pName = new string(name);
    this->age = age;
}

Critter::~Critter() //destructor definition
{
    cout << "Destructor called\n";
    delete pName;
}

Critter::Critter(const Critter& c) //copy constructor def
{
    cout << "Copy Constructor called\n";
    pName = new string(*(c.pName));
    age = c.age;
}

Critter& Critter::operator=(const Critter& c) //overloaded assignment op def
{
    cout << "Overloaded Assignment Operator called\n";
    if (this != &c)
    {
	delete pName;
	pName = new string(*(c.pName));
	age = c.age;
    }
    return *this;
}

void Critter::greet() const
{
    cout << "I'm " << *pName << " and I'm " << age << " years old.\n";
    cout << "&pName: " << &pName << endl;
}

void testDestructor();
void testCopyConstructor(Critter copy);
void testAssignmentOp();

int main()
{
    testDestructor();
    cout << endl;
    
    Critter crit("Poochie", 5);
    crit.greet();
    testCopyConstructor(crit);
    crit.greet();
    cout << endl;

    testAssignmentOp();
    
    return 0;
}

void testDestructor()
{
    Critter toDestroy("Rover", 3);
    toDestroy.greet();
}

void testCopyConstructor(Critter copy)
{
    copy.greet();
}

void testAssignmentOp()
{
    Critter crit1("crit1", 7);
    Critter crit2("crit2", 9);
    crit1 = crit2;
    
    crit1.greet();
    crit2.greet();
    cout << endl;
    Critter crit3("crit", 11);
    crit3 = crit3;
    crit3.greet();
}
