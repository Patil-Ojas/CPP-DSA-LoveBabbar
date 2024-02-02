#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    bool isSafe(vector<vector<int>> &m, int x, int y, int n, vector<vector<int>> &visited)
    {
        // cout<<"oof";
        // cout<<x<<" "<<y<<" "<<n<<" "<<endl;
        // cout<<visited[x][y]<<" "<<m[x][y]<<endl;
        
        if ((x>=0 and x<n) and (y>=0 and y<n) and visited[x][y] == 0 and m[x][y]==1)
        {
            // cout<<"brug";
            return true;
        }
        else
        {
            // cout<<"oof2";
            return false;
        }
    }
    
    void solve3000(vector<vector<int>> &m, vector<string> &ans, int x, int y, int n, string path, vector<vector<int>> &visited)
    {
        if (x==n-1 and y==n-1)
        {
            ans.push_back(path);
            return ;
        }
        
        // cout<<"bru";
        visited[x][y]=1;
        
        // down
        int new_x = x+1;
        int new_y = y;
        
        if (isSafe(m, new_x, new_y, n, visited))
        {
            // cout<<"bruh1";
            path.push_back('D');
            solve3000(m, ans, new_x, new_y, n, path, visited);
            // if the chosen path is not the correct path, ie backtrack in a way
            path.pop_back();
        }
        
        // left
        new_x = x;
        new_y = y-1;
        
        if (isSafe(m, new_x, new_y, n, visited))
        {
            // cout<<"bruh2";
            path.push_back('L');
            solve3000(m, ans, new_x, new_y, n, path, visited);
            // if the chosen path is not the correct path, ie backtrack in a way
            path.pop_back();
        }
        
        // right
        new_x = x;
        new_y = y+1;
        
        if (isSafe(m, new_x, new_y, n, visited))
        {
            path.push_back('R');
            solve3000(m, ans, new_x, new_y, n, path, visited);
            // if the chosen path is not the correct path, ie backtrack in a way
            path.pop_back();
        }
        
        // up
        new_x = x-1;
        new_y = y;
        
        if (isSafe(m, new_x, new_y, n, visited))
        {
            path.push_back('U');
            solve3000(m, ans, new_x, new_y, n, path, visited);
            // if the chosen path is not the correct path, ie backtrack in a way
            path.pop_back();
        }
        
        visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        int x = 0;
        int y = 0;
        vector<vector<int>> visited = m;
        string path = "";
        
        
        if (m[0][0] == 0)
            return ans;
        
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[i][j] = 0;
            }
        }
        
        solve3000(m, ans, x, y, n, path, visited);
        return ans;
    }
};

    