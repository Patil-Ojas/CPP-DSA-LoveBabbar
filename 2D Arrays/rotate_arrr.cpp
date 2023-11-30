
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int start=0;
        int end=n-1;
        
        while (start<end)
        {
            for (int i=0; i<n-1-start*2; i++)
            {
                swap(matrix[start][i+start], matrix[i+start][end]);
                swap(matrix[start][i+start], matrix[end][end-i]);
                swap(matrix[start][i+start], matrix[end-i][start]);
            }
            start++;
            end--;
        }
        
        // for (int i=0; i<n; i++)
        // {
        //     for (int j=0; j<n; j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
};