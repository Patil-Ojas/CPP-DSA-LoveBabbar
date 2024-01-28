#include <bits/stdc++.h> 
#include <vector>
#include <string.h>
using namespace std;

void solve3000(string str, vector <string> &ans, string output, int index)
{
	if (index >= str.length())
	{
		if (output.length() != 0)
			ans.push_back(output);
		return ;
	}

	solve3000(str, ans, output, index+1);

	// im a god
	output = output + str[index];
	solve3000(str, ans, output, index+1);
}

vector<string> subsequences(string str){
	vector<string> ans;
	string output;
	int index = 0;

	solve3000(str, ans, output, index);
	return ans;
}
