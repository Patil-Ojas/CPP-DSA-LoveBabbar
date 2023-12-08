#include <vector>
using namespace std;

// O(n*log(logn))

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n, true);

        // prime[0]=prime[1]=false;

        for (int i=2; i<n; i++)
        {
            if (prime[i])
            {
                count++;
                //mark the entire table of i as false
                for (int j=i*2; j<n; j=j+i)
                    prime[j]=0;
            }
        }

        return count;
    }
};