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

    ~Hero() {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    Hero a;

    Hero *b = new Hero();
    delete b;
}
