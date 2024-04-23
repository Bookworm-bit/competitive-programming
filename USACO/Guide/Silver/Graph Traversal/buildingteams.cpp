#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& colors, int c) {
	visited[node] = true;
	colors[node] = c;
	for (auto next : adj[node]) {
		if (!visited[next]) {
			colors[next] = c;
			dfs(next, adj, visited, colors, c);
		}
	}
}

// check if bipartite is sol

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
	vector<int> colors(n);
	int cc = 1;
	for (int i=0; i<n; i++) {
		if (!visited[i]) {
			if (cc > 2) break;
			cc *= -1;
			dfs(i, adj, visited, colors, cc);
		}
	}
	
	int temp = 1;
	for (int i=0; i<n-1; i++) {
		if (colors[i] == temp) {
			temp *= -1;
		} else {
			cout << "IMPOSSIBLE" << '\n';
			break;
		}
	}

	for (int i=0; i<n-1; i++) {
		cout << colors[i] << ' ';
	}
	cout << colors[n-1] << '\n';
}
