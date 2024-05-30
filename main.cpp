#include <iostream>
#include <string>
using namespace std;
class character
{
    protected:
    string name;
    int hp;
    int atk;

    public:
    character(string n, int h, int a) : name(n), hp(h), atk(a) {}

    string getName() const {
        return name;
    }

    int getHP() const {
        return hp;
    }

    int getAttack() const {
        return atk;
    }
    void takeDamage(int damage) {
        hp -= damage;
    }
    void attack(character& target) {
        int damage = rand() % atk + 1; 
        cout << name << " attacks " << target.getName() << " for " << damage << " damage.\n";
        target.takeDamage(damage);
    }    

};
class player :public character
{
    public:
    player (string n,int h,int a):character(n,h,a){}
    
};
class enemy : public character {
public:
    enemy(string n, int h, int a) : character(n, h, a) {}
};
class boss : public character {
public:
    boss(string n, int h, int a) : character(n, h, a) {}
};
int main()
{
    player p("NEW_PLAYER", 100, 10);
    enemy e("Enemy", 50, 5);
    boss b("Boss", 200, 20);

    p.attack(e);
    cout << "Enemy HP after player's attack: " << e.getHP() << endl;

    e.attack(p);
    cout << "Player HP after enemy's attack: " << p.getHP() << endl;

    b.attack(p);
    cout << "Player HP after boss's attack: " << p.getHP() << endl;

    return 0;
}