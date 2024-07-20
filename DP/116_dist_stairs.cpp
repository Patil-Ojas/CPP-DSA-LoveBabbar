#include <bits/stdc++.h> 
// # define MOD = 10000003
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if (nStairs<=0)
        return 0;
    else if (nStairs==1)
        return 1;
    else if (nStairs==2)
        return 2;
    else
    {
        long long int arr[nStairs+1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for (int i=3; i<=nStairs; i++)
        {
            // arr[i] = ((arr[i-1])%MOD+(arr[i-2])%MOD)%MOD;
            arr[i] = arr[i-1]+arr[i-2];
        }
        // cout<<""
        return arr[nStairs];
    }
}