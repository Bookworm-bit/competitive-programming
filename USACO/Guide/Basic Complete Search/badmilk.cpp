#include <bits/stdc++.h>
using namespace std;

struct Action {
	int time;
	int cow;
	int milk;
};

bool custom(Action a, Action b) {
	// it is necessary to sort the milks
	// because we need the -1 at the front if there is one
	// since the milk must be drank at a time strictly before sickness
	// and so if there are milks drank at the same point in time along with infection
	// then we might not find a contradictory case
	// if the milk is drank at the same time as infection but ordered before in input
	return a.time != b.time ? a.time < b.time : a.milk < b.milk;
}

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("badmilk");

	int N, M, D, S;
	cin >> N >> M >> D >> S;

	vector<Action> actions;
	for (int i=0; i<D; i++) {
		int p, m, t;
		cin >> p >> m >> t;

		Action a;
		a.time = t;
		a.cow = p;
		a.milk = m;

		actions.push_back(a);
	}

	for (int i=0; i<S; i++) {
		int p, t;
		cin >> p >> t;

		Action a;
		a.time = t;
		a.cow = p;
		a.milk = -1;

		actions.push_back(a);
	}

	sort(actions.begin(), actions.end(), custom);

	int maxDoses = -1;
	for (int i=1; i<=M; i++) {
		vector<bool> drank(N, false);

		bool next = false;
		for (auto a : actions) {
			if (a.milk == i) {
				drank[a.cow-1] = true;
			} else if (a.milk == -1) {
				if (!drank[a.cow-1]) { next = true; break; }
			}
		}

		if (next) continue;

		int doses = 0;
		for (auto c : drank) {
			doses += c;
		}
		maxDoses = max(maxDoses, doses);
	}

	cout << maxDoses << '\n';
}
