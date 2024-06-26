// spanning tree is a tree which is converted from a graph and has n nodes and n-1 edges
// minimum spanning tree -> spanning tree wiht minimum cost of wieghts
// for this we use PRIMS Algo

// not tested yet cuz servers are cooked
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_pair<int, list<pair<int, int>>> adj;

    for (int i=0; i<g.size(); i++)
    {
        // since this is 1 indexed we dont subtract 1
        int u = g[i][0];
        int v = g[i][1];
        int w = g[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for (int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i=1; i<n; i++)
    {
        int min = INT_MAX;
        int u;

        // find min node
        for (int v=1; v<n; v++)
        {
            if (mst[v]==false and key[v]<mini)
            {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for (auto it:adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v]==false and w<key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }

        vector<pair<pair<int, int>, int>> res;
        for (int i=2; i<=n; i++)
            res.push_back({{parent[i], i}, key[i]});

        return res;

    }
}