#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N, P;
		cin >> N >> P;

		vector<int> f(N);
		for (int i=0; i<N; i++) {
            char c;
			cin >> c;

            f[i] = c - '0';
		}

		vector<int> s(N);
		for (int i=0; i<N; i++) {
			char c;
			cin >> c;

            s[i] = c - '0';
		}

		int firstGoDown = N-1;
		for (int i=0; i<N; i++) {
			if (f[i] != f[0]) {firstGoDown = i-1; break;}
		}

		int secondGoDown = N-1;
        for (int i=0; i<N; i++) {
			if (s[i] != s[0]) {secondGoDown = i-1; break;} 
		}

        if (s[0] == f[0]) {
            firstGoDown = -1;
            secondGoDown = -1;
        }

        int M = 0;
        int prev = -1;
        int idx = N-1;
        vector<int> beaker;
        vector<string> moves;
        if (firstGoDown > secondGoDown) {
            for (int i=N-1; i>firstGoDown; i--) {
                if (f[i] != prev) {
                    prev = f[i];
                    M++;

                    if (P != 1) moves.push_back("1 3");
                    beaker.push_back(f[i]);
                }
            }

            prev = -1;
            for (int i=N-1; i>secondGoDown; i--) {
                if (s[i] != prev) {
                    M++;
                    if (P != 1) {
                        if (s[i] == f[0]) moves.push_back("2 1");
                        else moves.push_back("2 3");
                    }
                    if (s[i] != f[0]) beaker.push_back(s[i] == f[0] ? 1 : 2);
                    prev = s[i];
                }
            }
        } else {
            for (int i=N-1; i>secondGoDown; i--) {
                if (s[i] != prev) {
                    prev = s[i];
                    M++;

                    if (P != 1) moves.push_back("2 3");
                    beaker.push_back(f[i] == s[0] ? 2 : 1);
                }
            }

            prev = -1;
            for (int i=N-1; i>firstGoDown; i--) {
                if (f[i] != prev) {
                    M++;
                    if (P != 1) {
                        if (f[i] == s[0]) moves.push_back("1 2");
                        else moves.push_back("1 3");
                    }
                    if (f[i] != s[0]) beaker.push_back(f[i] == s[0] ? 2 : 1);
                    prev = f[i];
                }
            }
        }

        prev = -1;
        for (int i=beaker.size()-1; i>=0; i--) {
            int b = beaker[i];
            if (b != prev) {
                M++;
                if (P != 1) moves.push_back("3 " + to_string((b == f[0]) ? 1 : 2));
                prev = b;
            }
        }

        cout << M << '\n';
        for (auto m : moves) {
            cout << m << '\n';
        }
	}
}