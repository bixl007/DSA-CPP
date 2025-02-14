#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers
{
public:
    vector<int> arr;
    int prod = 1;
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
        {
            arr.clear();
            prod = 1;
        }
        else
        {
            prod *= num;
            arr.push_back(prod);
        }
    }

    int getProduct(int k)
    {
        if (arr.size() < k)
            return 0;
        if (arr.size() == k)
            return arr.back();
        return (arr.back() / arr[arr.size() - k - 1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */