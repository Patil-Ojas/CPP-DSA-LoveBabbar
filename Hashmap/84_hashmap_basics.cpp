// hasmap uses hash table as backend
// ordered map uses BST
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mp;

    pair<string, int> p = make_pair("bruh", 4);
    mp.insert(p);
    pair<string, int> p1 = make_pair("bruhmoment", 5);
    mp.insert(p1);
    mp["kanatahaluka"] = 6;
    
    // same
    cout<<mp["bruh"]<<endl;
    cout<<mp.at("kanatahaluka")<<endl;

    // initially gives error
    // cout<<mp.at("yourname")<<endl;
    
    // auto generates a 0
    cout<<mp["yourname"]<<endl;
    cout<<mp.at("yourname")<<endl;
    
    // size
    cout<<mp.size()<<endl;

    // to check presence (0 or 1)
    cout<<mp.count("bruh")<<endl;
    cout<<mp.count("brug")<<endl;

    // yeet
    cout<<mp.size()<<endl;
    mp.erase("bruhmoment");
    cout<<mp.size()<<endl;

    // to traveerse and print
    for (auto i:mp)
        cout<<i.first<<" "<<i.second<<endl;
    
    // iterator
    unordered_map<string, int> :: iterator it = mp.begin();
    while (it != mp.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    // if we use map, it is no longer random order wow
    // unordered -> constant
    // ordered -> logn
    return 0;
}