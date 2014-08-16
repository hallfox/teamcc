//Overriding Boss
//Demonstrates calling and overriding base member functions

#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy(int damage=10);
    void virtual taunt() const; //made virtual to be overridden
    void virtual attack() const;

private:
    int damage;
};

Enemy::Enemy(int damage):
    damage(damage)
{}

void Enemy::taunt() const
{
    cout << "The enemy says he will fight you.\n";
}

void Enemy::attack() const
{
    cout << "Attack! Inflicts " << damage << " damage points.";
}

class Boss : public Enemy
{
public:
    Boss(int damage=30);
    void virtual taunt() const; //optional use of virutal keyword
    void virtual attack() const;
};

Boss::Boss(int damage):
    Enemy(damage) //call base class constructor with argument
{}

void Boss::taunt() const
{
    cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::attack() const //override base class member function
{
    Enemy::attack(); //call base class member function
    cout << " And laughs heartily at you.\n";
}

int main()
{
    cout << "Enemy object:\n";
    Enemy enemy;
    enemy.taunt();
    enemy.attack();
    
    cout << "\n\nBoss object:\n";
    Boss boss;
    boss.taunt();
    boss.attack();

    return 0;
}
