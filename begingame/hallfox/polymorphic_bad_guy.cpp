//Polymorphic Bad Guy
//Demonstrates calling member functions dynamically

#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy(int damage=10);
    virtual ~Enemy();
    void virtual attack() const;

protected:
    int* pDamage;
};

Enemy::Enemy(int damage)
{
    pDamage = new int(damage);
}
Enemy::~Enemy()
{
    cout << "In Enemy destructor, deleting pDamage.\n";
    delete pDamage;
    pDamage = 0;
}

void Enemy::attack() const
{
    cout << "An enemy attacks and inflicts " << *pDamage << " damage points.";
}

class Boss: public Enemy
{
public:
    Boss(int multiplier=3);
    virtual ~Boss();
    void virtual attack() const;

protected:
    int* pMultiplier;
};

Boss::Boss(int multiplier)
{
    pMultiplier = new int(multiplier);
}

Boss::~Boss()
{
    cout << "In Boss destructor, deleting pMultiplier.\n";
    delete pMultiplier;
    pMultiplier = 0;
}

void Boss::attack() const
{
    cout << "A boss attacks and inflicts " << (*pDamage) * (*pMultiplier) << " damage points.";
}

int main()
{
    cout << "Calling attack() on boss object through pointer to Enemy:\n";
    Enemy* pBadGuy = new Boss();
    pBadGuy->attack();

    cout << "\n\nDeleting pointer to Enemy:\n";
    delete pBadGuy;
    pBadGuy = 0;

    return 0;
}

