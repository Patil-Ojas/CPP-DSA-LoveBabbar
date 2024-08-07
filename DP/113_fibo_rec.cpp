// those who forget the past, are condemned to repeat it

// approaches -> top down
//            -> bottom up

// we use dp when we can get the optimized solution of a problem using the solution of a sub-section of the problem

// tc -> O(n)
// sc -> O(n)+O(n)

#include<bits/stdc++.h>
using namespace std;

int fib( int n, vector<int> &dp)
{
        if (n<=1)
                return n;
        
        if (dp[n]!=-1)
                return dp[n];
                
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
}

int main()
{
        int n;
        cin>>n;

        vector<int> dp(n+1);
        for (int i=0; i<=n; i++)
        {
                dp[i] = -1;
        }

        cout<<fib(n, dp);
        return 0;
}