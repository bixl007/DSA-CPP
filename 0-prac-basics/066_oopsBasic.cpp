#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    string name;
    static int timeToComplete;

    int getHealth()
    {
        return health;
    }
    void setHealth(int h)
    {
        health = h;
    }
};

int Hero::timeToComplete = 5;

int main()
{
    Hero ramesh;
    ramesh.name = "Ramesh";
    ramesh.setHealth(100);

    cout << "Time to complete is: " << Hero::timeToComplete << endl;
    cout << "Name of the Hero: " << ramesh.name << endl;
    cout << "Current Health of the Hero is: " << ramesh.getHealth() << endl;
}