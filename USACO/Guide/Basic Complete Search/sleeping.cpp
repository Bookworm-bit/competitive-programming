#include <bits/stdc++.h>
using namespace std;

bool isSame(int N, vector<int> a) {
    for (int i=1; i<N; i++) {
        if (a[i] != a[0]) {
            return false;
        }
    }
    return true;
}

int solve(int N, vector<int> a) {
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum += a[i];
    }

    for (int i=0; i<sum+1; i++) {
        if (i != 0 && sum % i != 0) continue;

        int cluster = 0;
        int exceeds = false;
        for (int j=0; j<N; j++) {
            cluster += a[j];

            if (cluster > i) {
                exceeds = true;
                break;
            }

            if (cluster == i) {
                cluster = 0;
            }
        }

        if (!exceeds) {
            if (i == 0) return 0;

            return N - (int) sum / i;
        }
    }
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> a(N);
		for (int i=0; i<N; i++) {
			cin >> a[i];
		}

		int changes = solve(N, a);
		cout << changes << '\n';
	}
}
