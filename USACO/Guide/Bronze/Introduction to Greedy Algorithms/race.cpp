#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void setIO(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("race");

	int K, N;
	cin >> K >> N;

	for (int _=0; _<N; _++) {
		int X;
		cin >> X;

		int speed = 0;
		int pos = 0;
		int time = 0;

		while (speed < X && pos < K) {
			speed++;
			pos += speed;
			time++;
		}

		while (pos < K) {
			int sum1 = pos + (speed + 1 + X + 1) * (speed + 1 - X - 1 + 1) / 2;
			int sum2 = pos + (speed + X + 1)*(speed - X - 1 + 1)/ 2;

			if (sum1 < K) {
				speed++;
			} else if (sum2 < K) {
				;
			} else {
				speed = max(speed-1, X);
			}

			pos += speed;
			time++;
		}

		cout << time << '\n';
	}
}