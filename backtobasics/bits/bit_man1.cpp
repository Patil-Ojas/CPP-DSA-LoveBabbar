//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string getbin(int n)
    {
        string ans = "";
        
        while (n>0)
        {
            int dig = n%2;
            n = (n-dig)/2;
            ans = ans + to_string(dig);
        }
        return ans;
    }
    int countbits(string binn)
    {
        int count = 0;
        for (int i=0; i<binn.length(); i++)
        {
            if (binn[i]=='1')
                count++;
        }
        return count;
    }
    int setBits(int N) {
       string binn = getbin(N);
       int ans = countbits(binn);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends