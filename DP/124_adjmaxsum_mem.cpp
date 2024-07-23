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

int maximumNonAdjacentSum(vector<int> &nums){
    // int n = nums.size();
    // int ans = solveRec(nums, n-1);

    int n = nums.size();
    vector<int> dp(n+1, -1);
    int ans = solveMem(nums, n-1, dp);

    return ans;
}