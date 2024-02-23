#include <bits/stdc++.h>
using namespace std;

int costs[100000];
bool visited[100000];

void dfs(int node, vector<vector<int>>& adj, int& ccCost) {
	visited[node] = true;

	for (auto next : adj[node]) {
		if (!visited[next]) {
			ccCost = min(costs[next], ccCost);
			dfs(next, adj, ccCost);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i=0; i<n; i++) {
		cin >> costs[i];
	}

	vector<vector<int>> adj(n, vector<int> ());
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;

		x--;
		y--;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	long long ret = 0;
	for (int i=0; i<n; i++) {
		vector<int> p = adj[i];
		if (!visited[i]) {
			int ccCost = costs[i];
			dfs(i, adj, ccCost);

			ret += ccCost;
		} 
	}

	cout << ret << '\n';
}