// one method is the normmal double for loop method with TC O(m*n) & SC O(1)
// trie

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for (int i=0; i<26; i++)
                children[i] = NULL;
            isTerminal = false;
            childCount = 0;
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
            root->childCount++;
            root->children[indx] = child;
        }

        // recurse
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void solve3000(string str, string &ans)
    {
        for (int i=0; i<str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // cout<<"bru";
                int indx = ch - 'a';
                root = root->children[indx];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie();

    for (int i=0; i<arr.size(); i++)
        t->insertWord(arr[i]);
    
    string ans = "";
    string first = arr[0];
    
    t->solve3000(first, ans);
    return ans;
}


