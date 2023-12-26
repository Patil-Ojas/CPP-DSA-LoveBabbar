
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    int indx=0;

    for (int i=0; i<s.length(); i++)
    {
        if (s[i]==' ')
        {
            reverse(s.begin()+indx, s.begin()+i);
            indx = i+1;
        }
        if (i==s.length()-1)
        {
            reverse(s.begin()+indx, s.end());
        }
    }

    cout<<s;
    return 0;
}