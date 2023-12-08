// https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&leftPanelTab=1


#include <bits/stdc++.h> 
#include <vector> 

// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
// 	vector<int> ans;
// 	int n1 = arr1.size();
// 	int n2 = arr2.size();

// 	int i = 0;
// 	int j = 0;

// 	while ((i!=n1) and (j!=n2))
// 	{
// 		if (arr1[i]==arr2[j])
// 		{
// 			ans.push_back(arr1[i]);
// 			i = i + 1;
// 			j = j + 1;
// 		}
// 		else if(arr1[i] < arr2[j])
// 		{
// 			i = i + 1;
// 		}
// 		else
// 		{
// 			j = j + 1;
// 		}
// 	}

// 	return ans;

// }