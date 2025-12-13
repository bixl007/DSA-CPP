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
    Hero h(10);
    cout << h.getHealth() << endl;

    Hero *dh = new Hero(11);
    cout << dh->getHealth() << endl;

    Hero Ramesh(20, "Ramesh");
    cout << Ramesh.name << " has health: " << Ramesh.getHealth() << endl;
}
