#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, T;
    cin >> N >> K >> T;

    vector<int> a(K);
    for (int i=0; i<K; i++) {
        cin >> a[i];
    }

    vector<int> order(N);
    for (int i=0; i<N; i++) {
        order[i] = i;
    }

    vector<int> new_order;
    copy(order.begin(), order.end(), back_inserter(new_order)); 
    for (int i=0; i<T % ((N*K)/2); i++) {
        for (int j=0; j<K; j++) {
            order[a[(j+1) % K]] = new_order[a[j]];
        }
        for (int j=0; j<K; j++) {
            a[j] = (a[j]+1) % N;
        }
        new_order = order;
    }

    for (int i=0; i<N-1; i++) {
        cout << order[i] << ' ';
    }
    cout << order[N-1] << '\n';
}