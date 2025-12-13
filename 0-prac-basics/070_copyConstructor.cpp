#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    string name;

    Hero(int health)
    {
        this->health = health;
    }

    Hero(int health, string name)
    {
        this->name = name;
        this->health = health;
    }

    // copy constructor - Note: There is already a copy constructor by default
    Hero(Hero *temp)
    {
        this->name = name;
        this->health = health;
    }

    int getHealth()
    {
        return health;
    }
    void setHealth(int h)
    {
        health = h;
    }
};

int main()
{
    Hero h(10, "Ramesh");
    Hero Ramesh(h);
    cout << Ramesh.name << " has health: " << Ramesh.getHealth() << endl;

    Hero h1(20, "xyz");
    Hero h2(45, "abc");
    cout << h1.name << " has health: " << h1.getHealth() << endl;
    cout << h2.name << " has health: " << h2.getHealth() << endl;

    h1 = h2;
    cout << h1.name << " has health: " << h1.getHealth() << endl;
    cout << h2.name << " has health: " << h2.getHealth() << endl;

    h1.name[0] = 'A';
    cout << h1.name << " has health: " << h1.getHealth() << endl;
    cout << h2.name << " has health: " << h2.getHealth() << endl;
}
