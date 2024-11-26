#include <bits/stdc++.h>
using namespace std;

int susdist(int x1, int y1, int x2, int y2) {
	return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

void setIO(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void dfs(int node, vector<bool> &visited, int &temp, vector<vector<int>> &coords) {
	visited[node] = true;
	temp++;

	for (int c=0; c<coords.size(); c++) {
		if (!visited[c] && susdist(coords[node][0], coords[node][1], coords[c][0], coords[c][1]) <= pow(coords[node][2], 2)) {
			dfs(c, visited, temp, coords);
		}
	}
}


int main() {
	setIO("moocast");

	int N;
	cin >> N;

	vector<vector<int>> coords(N);
	for (int i=0; i<N; i++) {
		int x, y, p;
		cin >> x >> y >> p;
		coords[i].push_back(x);
		coords[i].push_back(y);
		coords[i].push_back(p);
	}
	
	int ret = 0;
	for (int i=0; i<N; i++) {
		vector<bool> sus(N);

		int temp = 0;
		dfs(i, sus, temp, coords);

		ret = max(ret, temp);
	}

	cout << ret << '\n';
}
