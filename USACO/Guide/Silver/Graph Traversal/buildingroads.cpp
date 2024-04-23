#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[node] = true;
	for (auto next : adj[node]) {
		if (!visited[next]) {
			dfs(next, adj, visited);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n, vector<int> ());
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> visited(n);
	vector<int> colors;
	int cc = 0;
	for (int i=0; i<n; i++) {
		if (!visited[i]) {
			dfs(i, adj, visited);
			cc++;
			colors.push_back(i);
		}
	}

	cout << cc - 1 << '\n';
	for (int i=0; i<cc - 1; i++) {
		cout << colors[i] + 1 << ' ' << colors[i+1] + 1 << '\n';
	}
}
