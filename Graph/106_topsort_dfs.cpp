
// topological sort only applicable on DAG 
// linear ordering of vertices such that for every edge u-v, u appears before v

#include <bits/stdc++.h> 
void topSort(unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &stck, int node)
{
    visited[node] = 1;

    for (auto neighbour:adj[node])
    {
        if (!visited[neighbour])
        {
            topSort(adj, visited, stck, neighbour);
        }
    }
    stck.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> stck;

    for (int i=0; i<v; i++)
    {
        if (!visited[i])
        {
            topSort(adj, visited, stck, i);
        }
    }

    vector<int> ans;
    while (!stck.empty())
    {
        ans.push_back(stck.top());
        stck.pop();
    }
    return ans;
}