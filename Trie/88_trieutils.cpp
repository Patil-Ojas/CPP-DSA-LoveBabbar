/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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

class Trie {

public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
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

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(TrieNode* root, string word)
    {
        if (word.length()==0)
            return true ;
        
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

        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};