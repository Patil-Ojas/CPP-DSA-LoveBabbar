#include <bits/stdc++.h> 
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    void solve3000(vector<int> &nums, int index, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return ;
        }

        for (int j=index; j<nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve3000(nums, index+1, ans);

            // backtrack
            swap(nums[index], nums[j]);
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> ans;
        int index = 0;

        solve3000(nums, index, ans);
        return ans;
    }
};