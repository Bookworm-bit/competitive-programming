#include <bits/stdc++.h>
using namespace std;

int MAX_N = 3000;
vector<vector<int>> adj(MAX_N);
vector<bool> closed(MAX_N);

void dfs(int node, vector<bool> &visited) {
	visited[node] = true;

	for (auto con : adj[node]) {
		if (!closed[con] && !visited[con]) {
			dfs(con, visited);
		}
	}
}

void setIO(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("closing");

	int N, M;
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int connectedComponents = 0;
	vector<bool> visited(N, false);
	for (int j=0; j<N; j++) {
		if (!visited[j] && !closed[j]) {
			dfs(j, visited);
			connectedComponents++;
		}
	}
	cout << ((connectedComponents > 1) ? "NO" : "YES") << '\n';

	for (int i=0; i<N-1; i++) {
		int rem;
		cin >> rem;
		rem--;

		closed[rem] = true;

		int connectedComponents = 0;
		vector<bool> visited(N, false);
		for (int j=0; j<N; j++) {
			if (!visited[j] && !closed[j]) {
				dfs(j, visited);
				connectedComponents++;
			}
		}

		cout << ((connectedComponents > 1) ? "NO" : "YES") << '\n';
	}
	
}
