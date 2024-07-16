#include <stack>
using namespace std;

void solve(stack<int> &myStack, int x)
{

    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int temp = myStack.top();
    myStack.pop();

    solve(myStack, x);

    myStack.push(temp);
}

void reverseStack(stack<int> &stack)
{

    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    solve(stack, num);
}