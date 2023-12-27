
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;

    m[1] = "bob";
    m[13] = "og";
    m[10] = "zhar";

    // ordered map -> O(logn) (uses red black tree)
    // unordered map -> O(1) (uses hash)
    m.insert({6, "sans"});

    for (auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    cout<<endl;

    m.erase(10);
    for (auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    // finding element
    cout<<"13 yse or nah: "<<m.count(13)<<endl;
    // wont work cuz ig it returns a value?
    // cout<<"Last ele: "<<m.end()<<endl;
    //will work
    auto c = m.end();


    auto it = m.find(6);
    cout<<(*it).first<<endl;
    it++;
    cout<<(*it).second<<endl;
    it--;

    cout<<endl;
    cout<<endl;

    for (auto i=it; i!=m.end(); i++)
    {
        cout<<(*i).first<<endl;
    }
    return 0;
}
