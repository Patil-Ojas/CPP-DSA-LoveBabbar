
void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &temp, int node)
{
    temp.push_back(node);
    visited[node] = true;

    for (auto i:adj[node])
    {
        if (!visited[i])
        {
            dfs(adj, visited, temp, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // gotta make adj list first
    unordered_map<int, list<int>> adj;
    for (int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    for (int i=0; i<V; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            dfs(adj, visited, temp, i);
            ans.push_back(temp);
        }
    }
    return ans;
}