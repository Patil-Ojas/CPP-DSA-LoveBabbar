// for a dictionary - addword, search, reomoveword

#include <iostream>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for (int i=0; i<26; i++)
                children[i] = NULL;
            isTerminal = false;
        }
};

class Trie
{
    public:
        TrieNode* root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word)
        {
            // if terminal node
            if (word.length() == 0)
            {
                root->isTerminal = true;
                return ;
            }
            
            // assuming word to be in caps
            int indx = word[0] - 'a';
            TrieNode* child;

            // present or absent
            if (root->children[indx] != NULL)
            {
                child = root->children[indx];
            }
            else
            {
                child = new TrieNode(word[0]);
                root->children[indx] = child;
            }

            // recurse
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word)
        {
            if (word.length()==0)
                return root->isTerminal ;
            
            int indx = word[0] - 'a';
            TrieNode* child;

            // present or absent
            if (root->children[indx] != NULL)
            {
                child = root->children[indx];
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
};


int main()
{
    Trie* t = new Trie();
    t->insertWord("bruh");

    cout<<t->searchWord("bruh")<<endl;
    cout<<t->searchWord("brug")<<endl;

    return 0;
}
