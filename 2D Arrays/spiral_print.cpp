#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int startrow = 0;
        int startcol = 0;
        int endrow = row-1;
        int endcol = col-1;

        int total = row*col;
        int words = 0;

        while (words<total)
        {
            for (int i=startcol; words<total and i<=endcol; i++)
            {
                ans.push_back(matrix[startrow][i]);
                words++;
            }
            startrow++;

            for (int i=startrow; words<total and i<=endrow; i++)
            {
                ans.push_back(matrix[i][endcol]);
                words++;
            }
            endcol--;

            for (int i=endcol; words<total and i>=startcol; i--)
            {
                ans.push_back(matrix[endrow][i]);
                words++;
            }
            endrow--;

            for (int i=endrow; words<total and i>=startrow; i--)
            {
                ans.push_back(matrix[i][startcol]);
                words++;
            }
            startcol++;
        }
        return ans;
    }
};