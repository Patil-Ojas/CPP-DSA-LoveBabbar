#include <string>
#include <iostream>
using namespace std;

string replaceSpaces(string &str){
	string strr;

	for(int i=0; i<str.length(); i++)
	{
		if (str[i]==' ')
		{
			strr.push_back('@');
			strr.push_back('4');
			strr.push_back('0');
		}
		else
		{
			strr.push_back(str[i]);
		}
	}
	return strr;
}