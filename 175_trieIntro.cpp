#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assuming word wiill be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;

                // Checking for children
                for (int i = 0; i < 26; i++)
                {
                    if (root->children[i] != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            return false; // word not found
        }

        int index = word[0] - 'A';
        TrieNode *child = root->children[index];

        if (child == NULL)
        {
            return false;
        }

        bool shouldDeleteCurrentNode = deleteUtil(child, word.substr(1));

        if (shouldDeleteCurrentNode)
        {
            delete child;
            root->children[index] = NULL;

            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    return false;
                }
            }

            return !root->isTerminal;
        }
        return false;
    }

    void deleteWord(string word)
    {
        deleteUtil(root, word);
    }
};

int main()
{

    // Insertion
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("XY");

    // Search
    cout << "Present or not " << t->searchWord("ABCD") << endl;
    cout << "Present or not " << t->searchWord("XY") << endl;
    cout << "Present or not " << t->searchWord("HDFGK") << endl;

    // Delete
    t->deleteWord("ABCD");
    cout << "Present or not " << t->searchWord("ABCD") << endl;

    return 0;
}