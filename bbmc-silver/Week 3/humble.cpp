// actually import the libraries (vector, algorithm, iostream, string) when submitting to POJ

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n) {
            break;
        }

        vector<int> humble(n);
        humble[0] = 1;

        int tracker[4] = {0, 0, 0, 0};
        for (int i = 1; i < n; i++) {
            int next_2 = humble[tracker[0]] * 2;
            int next_3 = humble[tracker[1]] * 3;
            int next_5 = humble[tracker[2]] * 5;
            int next_7 = humble[tracker[3]] * 7;

            int next = min(next_2, min(next_3, min(next_5, next_7)));
            humble[i] = next;

            if (humble[i] == humble[tracker[0]] * 2) {
                tracker[0]++;
            } 
            if (humble[i] == humble[tracker[1]] * 3) {
                tracker[1]++;
            }
            if (humble[i] == humble[tracker[2]] * 5) {
                tracker[2]++;
            } 
            if (humble[i] == humble[tracker[3]] * 7) {
                tracker[3]++;
            }
        }

        string suffix = "th";
        if (n % 10 == 1 && n % 100 != 11) {
            suffix = "st";
        } else if (n % 10 == 2 && n % 100 != 12) {
            suffix = "nd";
        } else if (n % 10 == 3 && n % 100 != 13) {
            suffix = "rd";
        }

        cout << "The " << n << suffix << " humble number is " << humble[n-1] << ".\n";
    }

    return 0;
}
