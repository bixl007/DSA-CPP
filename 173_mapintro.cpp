#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    // Unordered Map

    // Creation
    unordered_map<string, int> m;

    // Insertion
    pair<string, int> p = make_pair("XYRIX", 1);
    m.insert(p);

    pair<string, int> p2("Bixl", 2);
    m.insert(p2);

    m["Zod"] = 3;

    // Search
    cout << m["XYRIX"] << endl;
    cout << m.at("Bixl") << endl;

    cout << m["XYZ"] << endl;
    cout << m.at("XYZ") << endl;

    // Size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("Bixl") << endl;

    //  Erase
    m.erase("XYRIX");
    cout << m.size() << endl;

    // Iterator
    /*
    for (auto i : m)
    {
        cout << i.first << " : " << i.second << endl;
    }
    */
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    //              Map

    // Creation
    map<string, int> mp;

    // Insertion
    pair<string, int> p1 = make_pair("XYRIX", 1);
    mp.insert(p1);

    pair<string, int> p12("Bixl", 2);
    mp.insert(p12);

    mp["Zod"] = 3;

    // Search
    cout << mp["XYRIX"] << endl;
    cout << mp.at("Bixl") << endl;

    cout << mp["XYZ"] << endl;
    cout << mp.at("XYZ") << endl;

    // Size
    cout << mp.size() << endl;

    // to check presence
    cout << mp.count("Bixl") << endl;

    //  Erase
    mp.erase("XYRIX");
    cout << mp.size() << endl;

    // Iterator
    /*
    for (auto i : mp)
    {
        cout << i.first << " : " << i.second << endl;
    }
    */
    map<string, int>::iterator itm = mp.begin();
    while (itm != mp.end())
    {
        cout << itm->first << " " << itm->second << endl;
        itm++;
    }

    return 0;
}
