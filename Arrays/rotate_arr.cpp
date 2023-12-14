
#include <algorithm>
#include <vector>
using namespace std;

// approach 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> temp(nums.size());

        for (int i=0; i<nums.size(); i++)
        {
            temp[(i+k)%nums.size()] = nums[i];
        }
        nums = temp;
    }
};

//approach 2

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();

        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};