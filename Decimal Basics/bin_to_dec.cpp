
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int bs;
    cin>>bs;

    int i=0;
    int ans=0;

    while (bs!=0)
    {
        int rem = bs % 10;

        ans = ans + rem * pow(2, i);
        bs = bs / 10;
        i = i + 1;
    }

    cout<<ans;

    return 0;
}