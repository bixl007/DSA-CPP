#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    string name;

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
    Hero ramesh;
    ramesh.name = "Ramesh";
    ramesh.setHealth(100);

    cout << "Name of the Hero: " << ramesh.name << endl;
    cout << "Current Health of the Hero is: " << ramesh.getHealth() << endl;
}