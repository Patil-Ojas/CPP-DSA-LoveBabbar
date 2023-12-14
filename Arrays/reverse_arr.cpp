#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	reverse(arr.begin()+m+1, arr.end());
}
