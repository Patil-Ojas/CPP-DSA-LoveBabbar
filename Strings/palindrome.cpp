#include <bits/stdc++.h> 
#include <string>
#include <iostream>
using namespace std;

bool checkPalindrome(string s)
{
    // Write your code here.
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int start = 0;
    int end = s.length()-1;

    while (start<=end)
    {
        // cout<<"brug";
        if ((isalpha(s[start]) or isdigit(s[start])) and (isalpha(s[end]) or isdigit(s[end])))
        {
            // cout<<s[start]<<" pls"<<endl;
            if (s[start]==s[end])
            {
                // cout<<s[end]<<" pls2"<<endl;
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        else
        {   
           if (!(isalpha(s[start]) || isdigit(s[start]))) {
                // cout << s[end] << " pls2" << endl;
                // cout << s[start] << " pls2" << endl;
                start++;
            } else if (!(isalpha(s[end]) || isdigit(s[end]))) {
                // cout << "arukoto" << endl;
                end--;
            } else {
                cout << "nani";
            }
        }
    }
    return true;
}   