#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("triangles");

	int N;
	cin >> N;

	vector<vector<int>> posts(N);
	for (int i=0; i<N; i++) {
		vector<int> post(2);
		cin >> post[0] >> post[1];

		posts[i] = post;
	}

	int maxArea = -1e9;
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			for (int k=j+1; k<N; k++) {
				set<int> xValues;
				set<int> yValues;

				xValues.insert(posts[i][0]);
				yValues.insert(posts[i][1]);
				xValues.insert(posts[j][0]);
				yValues.insert(posts[j][1]);
				xValues.insert(posts[k][0]);
				yValues.insert(posts[k][1]);

				if (xValues.size() == yValues.size() && xValues.size() == 2) {
					int area = abs(posts[i][0] * (posts[j][1] - posts[k][1]) + posts[j][0] * (posts[k][1] - posts[i][1]) + posts[k][0] * (posts[i][1] - posts[j][1]));
					maxArea = max(maxArea, area);
				}
			}
		}
	}

	cout << maxArea << '\n';
}