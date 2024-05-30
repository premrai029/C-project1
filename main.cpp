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
int main()
{
    player p("Player", 100, 10);
    enemy e("Enemy", 50, 5);
    cout << "Player Name: " << p.getName() << ", HP: " << p.getHP() << ", Attack: " << p.getAttack() << endl;
    cout << "Enemy Name: " << e.getName() << ", HP: " << e.getHP() << ", Attack: " << e.getAttack() << endl;


    return 0;
}