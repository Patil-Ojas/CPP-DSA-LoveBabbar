// tanannanaaa

#include <iostream>

int factorial(int big)
{
    // we need to define base case - ie the stopping case
    // without this we get segmentation fault - ie memeory gg
    if (big==0)
    {
        return 1;
    }
    else
    {
        int small = big-1;
        return big*factorial(small);  
    }
}

int powerof2(int n)
{
    if (n==0)
        return 1;
    else
        return 2*powerof2(n-1);
}

int main()
{
    // jab badi problem choti solution se solve ho
    int n;
    std::cin>>n;

    int fact = factorial(n);
    std::cout<<fact<<"\n";

    int pow2 = powerof2(n);
    std::cout<<pow2;

    return 0;
}