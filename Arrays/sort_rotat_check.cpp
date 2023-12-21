class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i=1; i<n; i++)
        {
            if (nums[i-1]>nums[i])
            {
                count = count + 1;
            }
        }
        if (nums[n-1]>nums[0])
        {
            count = count + 1;
        }
        return count <= 1;
    }
};