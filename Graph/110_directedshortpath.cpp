#include <iostream>
#include <unordered_map>
#include <list>
#include <climits>
#include <stack>
#include <vector> 
using namespace std;

class Graph
{
    public:
    // we this pair for finding shortest distance
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        // directed
        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i:adj)
        {
            cout<<i.first<<" -> ";
            for (auto j:i.second)
            {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &stck)
    {
        vis[node] = true;

        for (auto neighbour: adj[node])
        {
            if (!vis[neighbour.first])
            {
                dfs(neighbour.first, vis, stck);
            }
        }
        stck.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> stck)
    {
        dist[src] = 0;

        while (!stck.empty())
        {
            int top = stck.top();
            stck.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto i:adj[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
            
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);

    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6;

    unordered_map<int, bool> visited;
    stack<int> stck;

    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, stck);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for (int i=0; i<n; i++)
        dist[i] = INT_MAX;

    g.getShortestPath(src, dist, stck);

    cout<<"answer is: "<<endl;

    for (int i=0; i<dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}