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
    Hero *a = new Hero;

    // (*a).setHealth(100);
    // (*a).name = "XYRIX";
    // cout << (*a).getHealth() << endl;
    // cout << (*a).name << endl;

    a->setHealth(100);
    a->name = "XYRIX";
    cout << a->getHealth() << endl;
    cout << a->name << endl;
}
