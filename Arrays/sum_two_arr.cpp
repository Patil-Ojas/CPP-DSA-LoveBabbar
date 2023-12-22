#include <bits/stdc++.h> 
#include <vector>
using namespace std;

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < n; i++) {
        num1 = num1 + a[i] * pow(10, n-i-1);
    }

    for (int i = 0; i < m; i++) {
        num2 = num2 + b[i] * pow(10, m-i-1);
    }

    int num = num1 + num2;
    vector<int> ans;

    while (num>0)
    {
        ans.push_back(num%10);
        num = num/10;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}