// we first create adj list
// then create parent
// then use bfs, cuz bfs inheritantly takes smallest path

// TC - O(N+E)
// SC - O(N+E)
#include <unordered_map>
#include <queue>
#include <list>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>> adj;

	for (int i=0; i<edges.size(); i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (auto i:adj[front])
		{
			if (!visited[i])
			{
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	int temp = t;
	vector<int> ans;
	ans.push_back(t);

	while (temp!=s)
	{
		temp = parent[temp];
		ans.push_back(temp);
	}

	reverse(ans.begin(), ans.end());

	return ans;
}
