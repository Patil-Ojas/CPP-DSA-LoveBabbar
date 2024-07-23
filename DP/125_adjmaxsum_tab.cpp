//  rec and mem and tab -> tc O(n)
//  rec and mem -> sc O(n)+O(n)
// tab sc -> O(n)
// space optimization possible but we move

#include <bits/stdc++.h> 
int solveRec(vector<int> &nums, int n)
{
    if (n<0)
        return 0;
    
    if (n==0)
        return nums[0];

    int inc = solveRec(nums, n-2)+nums[n]; 
    int exc = solveRec(nums, n-1); 

    return max(inc, exc);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp)
{
    if (n<0)
        return 0;
    
    if (n==0)
        return nums[0];

    if (dp[n]!=-1)
        return dp[n];
    
    int inc = solveMem(nums, n-2, dp)+nums[n]; 
    int exc = solveMem(nums, n-1, dp); 

    dp[n] = max(inc, exc);
    return dp[n];
}


int solveTab(vector<int> &nums, int n)
{
    vector<int> dp(n+1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<=n;i++)
    {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1];
        dp[i] = max(incl, excl);
    }
    return dp[n];
}




int maximumNonAdjacentSum(vector<int> &nums){
    // int n = nums.size();
    // int ans = solveRec(nums, n-1);

    // int n = nums.size();
    // vector<int> dp(n+1, -1);
    // int ans = solveMem(nums, n-1, dp);

    int n = nums.size();
    int ans = solveTab(nums, n-1);

    return ans;
}