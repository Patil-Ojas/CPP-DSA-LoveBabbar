
// LC Solutions
// 10 ms 

class Solution {
public:
    int fib(int n) {
        if (n==0)
            return 0;
        else if (n==1)
            return 1;
        else
            return fib(n-1)+fib(n-2);
    }
};

// better, 0ms
class Solution {
public:
    int fib(int n) {

        if (n==0)
            return 0;
        else if (n==1)
            return 1;
        else
        {
            int arr[n+1];
            arr[0] = 0;
            arr[1] = 1;

            for (int i=2; i<=n; i++)
            {
                arr[i] = arr[i-1] + arr[i-2];
            }
            // cout<<arr[n]<<endl;
            return arr[n];
        }
    }
};