#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	string s;
	cin >> s;

	int ret = 0;
	for (int i=N-2; i>=0; i-=2) {
		string temp = s.substr(i, 2);
		if (temp == "HG" && ret % 2 == 1) {
			ret++;
		} else if (temp == "GH" && ret % 2 == 0) {
			ret++;
		}
	}

	cout << ret << '\n';
}
