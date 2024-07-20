// step 1 -> get tle by recursion
// step 2 -> initialize dp(n+1)
// step 3 -> let base case remain same
// step 4 -> put dp[n] check case, return dp[n]
// step -> tadaa
class Solution {
public:
    int solve3000(vector<int> cost, int n, vector<int> dp)
    {
        if (n==0)
            return cost[0];
        
        if (n==1)
            return cost[1];

        if (dp[n]!=-1)
            return dp[n];
        
        dp[n] = min(solve3000(cost, n-1, dp), solve3000(cost, n-2, dp)) + cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1, -1);
        dp[n] = min(solve3000(cost, n-1, dp), solve3000(cost, n-2, dp));
        return dp[n];
    }
};