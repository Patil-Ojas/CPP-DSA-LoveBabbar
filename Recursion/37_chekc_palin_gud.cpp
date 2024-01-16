#include <bits/stdc++.h> 
#include <vector>
#include <iostream>
using namespace std;

bool rev_str(vector<int> ans, int start, int end)
{
	if (start > end)
	{	
		// cout<<start<<endl<<end<<endl;
		// cout<<"nruj";
		return true;
	}
	else if (ans[start] != ans[end])
		return false;
	else
	{
		// cout<<str[start]<<endl<<str[end]<<endl;
		// cout<<start<<endl<<end<<endl;
		return rev_str(ans, start+1, end-1);
	}
}

int to_binary(long long n)
{
    int i = 0;
    int ans = 0;

    while (n!=0)
    {
        int rem = n & 1;
        ans = (rem*pow(10, i)) + ans;
        n = n>>1;
        i++;
    }

	return ans;
}

bool checkPalindrome(long long N)
{
	// int bin = to_binary(N);
	// // cout<<bin<<endl;
	// string str = to_string(bin);
	// // cout<<str.length()<<endl;

	vector<int>ans;

    while(N!=0){

        if(N&1) {

            ans.push_back(1);

        }else{

            ans.push_back(0);

        }

        N= N>>1;
    }
	
	return rev_str(ans, 0, ans.size()-1);
}

int main() {
    long long N;
    cin >> N;

    if (checkPalindrome(N)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
