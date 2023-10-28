#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("art");

    int N;
    cin >> N;

    vector<vector<int>> canvas(N, vector<int>(N));
    vector<int> valid;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < N; j++) {
            int num = str[j] - '0';
            canvas[i][j] = num;

            if (count(valid.begin(), valid.end(), num) == 0 && num != 0) {
                valid.push_back(num);
            }
        }
    }

    for (int c=1; c<=9; c++) {
        int left = N;
        int right = -1;
        int top = N;
        int bottom = -1;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (canvas[i][j] == c) {
                    left = min(j, left);
                    right = max(j, right);
                    top = min(i, top);
                    bottom = max(i, bottom);
                }
            }
        }

        for (int i=top; i<bottom+1; i++) {
            for (int j=left; j<right+1; j++) {
                if (canvas[i][j] != c && canvas[i][j] != 0) {
                    valid.erase(remove(valid.begin(), valid.end(), canvas[i][j]), valid.end());
                }
            }
        }
    }

    cout << valid.size() << '\n';
}