// gives tle
// recursion done

class Solution {
public:
    int solve3000(vector<int> cost, int n)
    {
        if (n==0)
            return cost[0];
        
        if (n==1)
            return cost[1];
        
        int ans = min(solve3000(cost, n-1), solve3000(cost, n-2)) + cost[n];
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve3000(cost, n-1), solve3000(cost, n-2));
        return ans;
    }
};