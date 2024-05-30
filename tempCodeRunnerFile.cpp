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

    cout << "Player Name: " << p.name << ", HP: " << p.hp << ", Attack: " << p.atk << endl;
    cout << "Enemy Name: " << e.name << ", HP: " << e.hp << ", Attack: " << e.atk << endl;

    return 0;
}