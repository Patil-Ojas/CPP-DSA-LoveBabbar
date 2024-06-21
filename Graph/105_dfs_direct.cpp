#include <unordered_map>
#include <list>
#include <vector>

bool cycleCheck(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node)
{
  visited[node] = true;
  dfsvisited[node] = true;

  for (auto neighbour: adj[node])
  {
    if (!visited[neighbour])
    {
      bool check = cycleCheck(adj, visited, dfsvisited, neighbour);
      if (check)
        return true;
    }
    else if (dfsvisited[neighbour])
    {
      return true;
    }
  }
  dfsvisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++)  
    {
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for (int i=0; i<n; i++)
    {
      if (!visited[i])
      {
        bool ans = cycleCheck(adj, visited, dfsvisited, i);
        if (ans)
          return true;
      }
    }
    return false;
}