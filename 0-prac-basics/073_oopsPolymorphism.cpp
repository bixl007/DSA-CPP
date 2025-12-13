

#include <iostream>
using namespace std;

//                                                               Static Polymorphism

//                                 Function overloading
/*
class A
{
public:
    void sayHello()
    {
        cout << "Hello" << endl;
    }
    int sayHello(char name)
    {
        cout << "Hi there" << endl;
        return 1;
    }
    void sayHello(string name)
    {
        cout << "Hey" << endl;
    }
};

int main()
{
    A obj;
    obj.sayHello();

    return 0;
}
*/

//                                           operator overloading

/*
class B
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }

    void operator+(B &obj)
    {
        // int value1 = this->a;
        // int value2 = obj.a;
        // cout << "Output is: " << value2 - value1 << endl;

        cout << "Operator overloading occurred" << endl;
    }
};

int main()
{

    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
}
*/

//                                                                Dynamic Polymorphism

// Method overriding

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{

    Animal ob;
    ob.speak();

    Dog obj;
    obj.speak();

    return 0;
}