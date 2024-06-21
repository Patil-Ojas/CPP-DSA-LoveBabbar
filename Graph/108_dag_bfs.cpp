// kahsn algorithm or bfs 
// TC - O(N+E)
// SC - O(N+E)

#include <bits/stdc++.h> 


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++)
    {
      // since this sum deals with 1 indexing, we subtract 1
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // finding all indegree
    vector<int> indegree(n);

    for (auto i:adj)
    {
        for (auto j:i.second)
        {
            indegree[j]++;
        }
    }

    // pushing 0 indegre
    queue<int> q;
    for (int i=0; i<n; i++)
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
    
    if (ans.size()==n)
      return false;
    else
      return true;
}