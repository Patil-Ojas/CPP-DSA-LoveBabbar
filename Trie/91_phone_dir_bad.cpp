
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

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    vector<Trie*> tree;

    int i=0;
    string search = "";
    vector<vector<string>> ans(queryStr.length());

    for (int j=0; j<contactList.size(); j++)
    {
        Trie* t = new Trie();
        t->insertWord(contactList[j]);
        tree.push_back(t);
    }

    while (i<queryStr.length())
    {
        search = search + queryStr[i];

        for (int j=0; j<tree.size(); j++)
        {
            if (tree[j]->startsWith(search))
                ans[i].push_back(contactList[j]);
        }
        i++;
    }

    return ans;
}