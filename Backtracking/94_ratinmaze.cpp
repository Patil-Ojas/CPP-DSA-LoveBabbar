#include <bits/stdc++.h>

void find(vector<vector<int>>& m, int n, int x, int y, vector<vector<bool>>& visited, string s, vector<string>& ans) {

    if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || m[x][y] == 0) {

        return;

    }

    if (x == n - 1 && y == n - 1) {

        ans.push_back(s);

        return;


    }

    visited[x][y] = true;

    find(m, n, x + 1, y, visited, s + 'D', ans);

    find(m, n, x, y - 1, visited, s + 'L', ans);

    find(m, n, x, y + 1, visited, s + 'R', ans);

    find(m, n, x - 1, y, visited, s + 'U', ans);

    visited[x][y] = false;

}

 

vector<string> searchMaze(vector<vector<int>>& m, int n) {

    vector<string> ans;

    if (m[0][0] == 0) {

        return ans;

    }

    int srcx = 0;

    int srcy = 0;

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    string str;

    find(m, n, srcx, srcy, visited, str, ans);

    return ans;
}