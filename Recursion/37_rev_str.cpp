#include <bits/stdc++.h> 
#include <string>

void rev_str(string &str, int start, int end)
{
	if (start > end)
		return ;
	else
	{
		// cout<<str[start]<<" "<<str[end]<<endl;
		swap(str[start], str[end]);
		rev_str(str, start+1, end-1);
	}
}

string reverseString(string str)
{
	// int start = 0;
	// int end = str.length()-1;

	// if (end == 0)
	// 	return str;
		

	// string revstr = rev_str(str, start, end);
	rev_str(str, 0, str.length()-1);
	return str;
}