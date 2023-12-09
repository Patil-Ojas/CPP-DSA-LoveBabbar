
#include <bits/stdc++.h> 
#include <vector> 
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=0; i<n; i++)
        {
            nums1.pop_back();
        }
        
        int p1=0;
        int p2=0;
        vector<int> ans;

        while (p1<=m-1 and p2<=n-1)
        {  
            if (nums1[p1]<=nums2[p2])
            {
                ans.push_back(nums1[p1]);
                p1++;
            }
            else
            {
                ans.push_back(nums2[p2]);
                p2++;
            }
        }

        while (p1<=m-1)
        {
            ans.push_back(nums1[p1]);
            p1++;
        }

        while (p2<=n-1)
        {
            ans.push_back(nums2[p2]);
            p2++;
        }
        nums1 = ans;
    }
};