#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	vector<int> q(N);
	vector<int> v(N);
	for (int i=0; i<N; i++) {
		cin >> q[i] >> v[i];
	}

	int direction = 1;
	int power = 1;
	int ret = 0;
	set<int> destroyed;
	set<pair<int, int>> visited;
	while (S > 0 && S <= N) {
		if (visited.find(make_pair(S, power*direction)) != visited.end()) {
            break;
        }
        visited.insert(make_pair(S, power*direction));

		if (q[S-1]) {
			if (power >= v[S-1] && destroyed.find(S-1) == destroyed.end()) {
                destroyed.insert(S-1);
                ret++;
            }
		} else {
            power += v[S-1];
            direction *= -1;
        }
        S += direction * power;
	}

    cout << ret << '\n';
}