#include <bits/stdc++.h>
using namespace std;

struct movie {
	int a, b;
};

bool cmp(movie x, movie y) {
	return x.b < y.b;
}

int main() {
	int N;
	cin >> N;

	vector<movie> movies(N);
	for (int i=0; i<N; i++) {
		int a, b;
		cin >> a >> b;

		movie temp;
		temp.a = a;
		temp.b = b;
		movies[i] = temp;
	}

	sort(movies.begin(), movies.end(), cmp);

	int curr = 0;
	int ret = 0;
	for (auto m : movies) {
		if (m.a >= curr) {
			curr = m.b;
			ret++;
		}
	}

	cout << ret << '\n';
}
