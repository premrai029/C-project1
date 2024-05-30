#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
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
    srand(time(0));
    player p("NEW_PLAYER", 20, 3);
    enemy e("Enemy", 12, 4);
    boss b("Boss", 25, 5);

    cout << "=== Combat Begins ===\n\n";

    while (p.getHP() > 0 && e.getHP() > 0) {
        cout << "Player HP: " << p.getHP() << "\t" << e.getName() << " HP: " << e.getHP() << endl;
        p.attack(e);
        if (e.getHP() <= 0) {
            cout << e.getName() << " defeated!\n";
            break;
        }

        e.attack(p);
        if (p.getHP() <= 0) {
            cout << "Player defeated...\n";
            break;
        }
    }

    cout << "\n=== Combat Ends ===\n";
    return 0;
}