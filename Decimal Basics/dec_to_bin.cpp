// wont work here but works in online compilers crazy huh

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i = 0;
    
    int ans = 0;

    while (n!=0)
    {
        int rem = n & 1;

        ans = (rem*pow(10, i)) + ans;
        n = n>>1;
        i++;
    }


    cout<<"bin value: "<<ans;

    return 0;
}