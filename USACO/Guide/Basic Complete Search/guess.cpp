#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("guess");

	int N;
	cin >> N;

	map<string, vector<string>> animals;
	for (int i=0; i<N; i++) {
		string animal;
		cin >> animal;

		int K;
		cin >> K;

		vector<string> qualities(K);
		for (int j=0; j<K; j++) {
			cin >> qualities[j];
		}

		animals[animal] = qualities;
	}

	int maxYes = -1;
	for (auto guess : animals) {
		for (auto other : animals) {
			if (guess.first != other.first) {
				int c = 1;
				for (auto q : guess.second)  {
					c += count(other.second.begin(), other.second.end(), q);
				}

				maxYes = max(maxYes, c);
			}
		}
	}

	cout << maxYes << '\n';
}