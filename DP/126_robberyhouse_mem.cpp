#include <bits/stdc++.h> 

long long int solveMem(vector<int> &costs, int n, vector<long long int> &dp)
{
    if (n<0)
        return 0;
    
    if (n==0)
        return costs[0];
    
    if (dp[n]!=-1)
        return dp[n];
    
    long long int inc = solveMem(costs, n-2, dp) + costs[n];
    long long int exc = solveMem(costs, n-1, dp);

    dp[n] = max(inc, exc);
    return dp[n];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    
    if (n==1)
        return valueInHouse[0];
    
    vector<int> first;
    vector<int> sec;
    vector<long long int> dp1(n, -1);
    vector<long long int> dp2(n, -1);

    for (int i=0; i<n; i++)
    {
        if (i!=n-1)
            first.push_back(valueInHouse[i]);
        
        if (i!=0)
            sec.push_back(valueInHouse[i]);
    }

    long long int ans1 = solveMem(first, n-2, dp1);
    long long int ans2 = solveMem(sec, n-2, dp2);
    return max(ans1, ans2);
}