
#include <iostream>

// Macro, cant be changed throughout the program
// better the double pi = 3.14 since double pi takes lil space and can be changed within program
#define PI 3.14

// Global var - bad prac cuz any function can change its value 
int score = 1;

// inline functions - if our function is of a single line, then compiler makes exception
// no function call and lower memeory usage
// if 2 or 3 lines decision upto compiler
inline int getMax(int a, int b)
{
    return (a>b)?a:b;
}

// default arg - automatically used values as default when value isnt specified
// default args are right most aligned
inline int getMaxof99(int a, int b=99)
{
    return (a>b)?a:b;
}


int main()
{
    int a = 5;
    int b = 3;
    int max = getMax(a, b);
    std::cout<<max<<"\n";

    int maxx = getMaxof99(20);
    std::cout<<maxx;

    return 0;
}