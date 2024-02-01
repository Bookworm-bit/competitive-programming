#include <bits/stdc++.h>
using namespace std;

int main() {
	int Q;
	cin >> Q;

	for (int i=0; i<Q; i++) {
		string s;
		cin >> s;

		bool possible = false;
		vector<int> oLocations;
		for (int j=1; j<s.length()-1; j++) {
			if (s[j] == 'O') {
				possible = true;
				oLocations.push_back(j);
			}
		}

		int minMoves = (int) 1e9;
		for (auto o : oLocations) {
			int moves = s.length() - 3;
			if (s[o-1] == 'O') moves++;
			if (s[o+1] == 'M') moves++;
			minMoves = min(moves, minMoves);
		}

		if (possible) cout << minMoves << '\n';
		else cout << -1 << '\n';
	}
}
