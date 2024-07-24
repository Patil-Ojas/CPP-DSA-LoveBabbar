// 1d dp is when only one var changes in the rec func
// 2d dp will be 2 vars changing 

// here only n is changing so 1d dp

#include <climits>

int solveRec(int n, int x, int y, int z)
{
	if (n<0)
		return INT_MIN;
	
	if (n==0)
		return 0;
	
	int a = solveRec(n-x, x, y, z)+1;
	int b = solveRec(n-y, x, y, z)+1;
	int c = solveRec(n-z, x, y, z)+1;

	int ans = max(a, max(b, c));
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	
	int ans = solveRec(n, x, y, z);
	
	if (ans<0)
		return 0;
	else
		return ans;
}