//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xori = 0;
        vector<int> ans(2, 0);
        
        // get the 2 unique ele
        for (auto i:nums)
            xori = xori^i;
        
        
        // make mask
        int mask = xori&-xori;
        
        // get the ele
        for (auto i:nums)
        {
            if (i&mask)
                ans[0] = ans[0]^i;
            else
                ans[1] = ans[1]^i;
        }
        
        // asc order
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends