#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<string> sequence;
        bool stop = false;
        for (int i=0; i<M; i++) {
            int odd = 0;
            int even = 0;

            int largestOdd = -1;
            int smallestOdd = (int) 1e9+1;

            int largestEven = -1;
            int smallestEven = (int) 1e9+1;
            for (int j=0; j<K; j++) {
                int temp;
                cin >> temp;

                if (temp % 2 == 0) {
                    even++;
                    largestEven = max(temp, largestEven);
                    smallestEven = min(smallestEven, temp);
                }
                else {
                    odd++;
                    largestOdd = max(temp, largestOdd);
                    smallestOdd = min(smallestOdd, temp);
                }
            }

            if (stop) continue;

            //cout << N << " to ";
            if (N - max(largestEven, largestOdd) <= 0) {
                if (odd == 0) {
                    sequence.push_back("Even");
                    N += largestEven;
                } else if (even == 0) {
                    sequence.push_back("Odd");
                    N += largestOdd;
                } else {
                    stop = true;
                }
            } else if (N - largestEven <= 0) {
                sequence.push_back("Even");
                N -= largestOdd;
            } else if (N - largestOdd <= 0) {
                sequence.push_back("Odd");
                N -= largestEven;
            } else {
                sequence.push_back("Even");
                if (odd == 0) {
                    N += largestEven;
                } else {
                    N -= largestOdd;
                }
            }

            //cout << N << '\n';
        }

        if (!stop) {
            for (int i=0; i<M-1; i++) {
                cout << sequence[i] << ' ';
            }

            cout << sequence[M-1] << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }

    return 0;
}
