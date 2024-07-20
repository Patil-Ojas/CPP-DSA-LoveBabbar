// we can see that only the n value is changing in betwen recursing functions 

// step 1 -> dp array creation
// step 2 -> dp[0] and dp[1], base cases
// step 3 -> define for loop limits

// if you wanna optimize space, just use variable
class Solution {
public:
    int solve3000(vector<int> &cost, int n)
    {
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++)
            dp[i] = min(dp[i-1], dp[i-2])+cost[i];
        
        return min(dp[n-1], dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = solve3000(cost, n );
        return ans;
    }
};