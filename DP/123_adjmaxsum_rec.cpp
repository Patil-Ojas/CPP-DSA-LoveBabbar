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
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans = solveRec(nums, n-1);
    return ans;
}