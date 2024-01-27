#include <bits/stdc++.h> 
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    void solve3000(vector<int> &nums, vector<vector<int>> &ans, vector<int> output, int index)
    {
        if (index>=nums.size())
        {
            ans.push_back(output);
            return ;
        }
        
        //exclude case
        solve3000(nums, ans, output, index+1);

        // include 
        int ele = nums[index];
        output.push_back(ele);
        solve3000(nums, ans, output, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve3000(nums, ans, output, index);
        return ans;
    }
};