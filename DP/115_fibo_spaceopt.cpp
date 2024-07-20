// tc -> O(n)
// sc -> O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin>>n;

        int prev1 = 0;
        int prev2 = 1;

        if (n==0)
                return prev1;

        for (int i=2; i<=n; i++)
        {
                int curr = prev1+prev2;
                prev1 = prev2;
                prev2 = curr;
        }
        cout<<prev2<<endl;
        return 0;
}