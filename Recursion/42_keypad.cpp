#include <bits/stdc++.h> 
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    void solve3000(string digits, string output, vector<string> &ans, string mapping[], int index)
    {
        if (output.length() >= digits.length())
        {
            ans.push_back(output);
            return ;
        }

        int num = digits[index] - '0';
        string value = mapping[num];

        for (int i=0; i<value.length(); i++)
        {
            output = output + value[i];
            solve3000(digits, output, ans, mapping, index+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        if (digits.length() <= 0)
            return ans;

        string output;
        int index = 0;
        string mapping[10] = {"", "" , "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve3000(digits, output, ans, mapping, index);
        return ans;
    }
};