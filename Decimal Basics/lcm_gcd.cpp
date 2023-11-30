#include <iostream>
using namespace std;

int getlcm(int a, int b, int gcd)
{
    // relation: gcd*lcm = a*b
    return (a*b)/gcd;
}

int findgcd(int a, int b)
{
    if (a==0)
        return b;
    
    if (b==0)
        return a;
    
    while (a!=b)
    {
        if (a>b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
int main()
{
    int a, b;
    cin>>a>>b;

    int gcd = findgcd(a, b);
    int lcm = getlcm(a, b, gcd);

    cout<<"GCD: "<<gcd<<endl;
    cout<<"LCM: "<<lcm<<endl;
    return 0;
}