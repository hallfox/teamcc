//Simple Boss
//Demonstrates inheritance

#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy();
    int damage;
    void attack() const;
};

Enemy::Enemy():
    damage(10)
{}

void Enemy::attack() const
{
    cout << "Attack inflicts " << damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
    Boss();
    int damageMultiplier;
    void specialAttack() const;
};

Boss::Boss():
    damageMultiplier(3)
{}

void Boss::specialAttack() const
{
    cout << "Special Attack inflicts " << (damageMultiplier * damage);
    cout << " damage points!\n";
}

int main()
{
    cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.attack();
    
    cout << "\nCreating a boss.\n";
    Boss boss1;
    boss1.attack();
    boss1.specialAttack();
    
    return 0;
}
