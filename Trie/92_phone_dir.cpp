
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

        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix)
        {
            if (curr->isTerminal)
                temp.push_back(prefix);
            
            for (char ch='a'; ch<='z'; ch++)
            {
                TrieNode* next = curr->children[ch-'a'];

                if (next!=NULL)
                {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
            return ;
        }

        vector<vector<string>> getSuggestions(string str)
        {
            TrieNode* prev = root;
            vector<vector<string>> output;
            string prefix = "";

            for (int i=0; i<str.length(); i++)
            {
                char lastch = str[i];
                prefix.push_back(lastch);

                TrieNode* curr = prev->children[lastch-'a'];

                // not found
                if (curr == NULL)
                    break; 

                // found
                vector<string> temp;
                printSuggestions(curr, temp, prefix);

                output.push_back(temp);
                
                temp.clear();
                prev = curr;
            }
            return output;
        }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie();

    int i=0;
    string search = "";
    vector<vector<string>> ans(queryStr.length());

    for (int j=0; j<contactList.size(); j++)
    {
        t->insertWord(contactList[j]);
    }

    return t->getSuggestions(queryStr);
}
