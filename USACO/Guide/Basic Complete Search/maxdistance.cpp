#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> x_values(N);
    vector<int> y_values(N);
    for (int i=0; i<N; i++) {
        cin >> x_values[i];
    }
    for (int i=0; i<N; i++) {
        cin >> y_values[i];
    }

    long long max_distance = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            long long distance = (long long) pow(x_values[i] - x_values[j], 2) + (long long) pow(y_values[i] - y_values[j], 2);
            max_distance = max(distance, max_distance);
        }
    }
    cout << max_distance << '\n';
}