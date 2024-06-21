// kahsn algorithm or bfs 
// TC - O(N+E)
// SC - O(N+E)

#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // finding all indegree
    vector<int> indegree(v);

    for (auto i:adj)
    {
        for (auto j:i.second)
        {
            indegree[j]++;
        }
    }

    // pushing 0 indegre
    queue<int> q;
    for (int i=0; i<v; i++)
    {
        if (indegree[i]==0)
            q.push(i);
    }

    // bfs
    vector<int> ans;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        for (auto neighbour:adj[temp])
        {
            indegree[neighbour]--;

            if (indegree[neighbour]==0)
                q.push(neighbour);

        }
    }
    return ans;
}