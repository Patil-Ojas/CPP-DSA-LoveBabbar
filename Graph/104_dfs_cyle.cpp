#include<unordered_map>
#include<list>
#include<queue>

bool isCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int parent, int node)
{
    visited[node] = 1;

    for (auto neighbour: adj[node])
    {
        if (visited[neighbour]==true and parent!=neighbour)
            return true;
        else if (!visited[neighbour])
        {
            bool cycleCheck = isCycleDFS(adj, visited, node, neighbour);
            if (cycleCheck)
                return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycleDFS(adj, visited, -1, i);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}
