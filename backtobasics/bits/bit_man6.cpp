//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string getString(int n)
    {
        string ans = "";
        while (n>0)
        {
            ans = to_string(n%2) + ans;
            n = n/2;
        }
        return ans;
    }
    int findPosition(int N) {
        if (N==0)
            return -1;
            
        string binn = getString(N);
        
        int leng = binn.length();
        int count = 0;
        int ans;
        
        for (int i=0; i<leng; i++)
        {
            if (binn[i]=='1')    
            {
                count++;
                ans = i;
                if (count>1)
                    return -1;
            }
        }
        return leng-ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends