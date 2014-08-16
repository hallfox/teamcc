//Simple Boss 2.0
//Demonstrates access control under inheritance

#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy();
    void attack() const;
    
protected:
    int damage;
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
    void specialAttack() const;
private:
    int damageMultiplier;
};

Boss::Boss():
    damageMultiplier(3)
{}

void Boss::specialAttack() const
{
    cout << "Special attack inflicts " << (damageMultiplier * damage);
    cout << " damage points!\n";
}

class FinalBoss: public Boss
{
public:
    FinalBoss();
    void desperationAttack() const;

private:
    int desperationMultiplier;
};

FinalBoss::FinalBoss(): desperationMultiplier(10) {}

void FinalBoss::desperationAttack() const
{
    cout << "Desperation attack inflicts " << (desperationMultiplier * damage) << " damage point! Ouch!\n";
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

    cout << "\nCreating the final boss.\n";
    FinalBoss finalBoss;
    finalBoss.attack();
    finalBoss.specialAttack();
    finalBoss.desperationAttack();

    return 0;
}
