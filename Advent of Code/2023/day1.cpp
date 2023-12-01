#include <bits/stdc++.h>
using namespace std;

int main() {
	int N = 1000;
	long long sum = 0;
	for (int i=0; i<N; i++) {
		string s;
		cin >> s;

		for (int j=0; j<(int) s.length(); j++) {
			if (isdigit(s[j])) {
				sum += 10 * (s[j] - '0');
				break;
			}
		}

		for (int j=(int) s.length()-1; j>=0; j--) {
			if (isdigit(s[j])) {
				sum += (s[j] - '0');
				break;
			}
		}
	}

	cout << sum << '\n';
}
