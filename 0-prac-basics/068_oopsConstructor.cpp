#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    string name;

    Hero()
    {
        cout << "Constructor Invoked" << endl;
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
    Hero h;
    Hero *a = new Hero;
}
