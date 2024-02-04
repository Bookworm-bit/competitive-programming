#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int odd = 0;
	int even = 0;
	for (int i=0; i<N; i++) {
		int temp;
		cin >> temp;

		if (temp % 2 == 0) even++;
		else odd++;
	}

	if (even > odd) {
		cout << 2*odd + 1 << '\n';
	} else if (even == odd) {
		cout << 2*odd << '\n';
	} else {
        while (even - odd < 0) {
            odd -= 2;
            even++;
        }

		if (even - odd == 2) even--;

        cout << odd + even << '\n';
	}
}
