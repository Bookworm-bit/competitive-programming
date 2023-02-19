#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int b=0; b<t; b++) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		int count = 0;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if ((i >= 1) && (i != j) && (abs(a[i] - a[j]) == abs(*max_element(a.begin(), a.end()) - *max_element(a.begin(), a.end())))) {
					count++;
				}
			}
		}
		cout << count + 2 << '\n';
	}
}
