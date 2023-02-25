#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("cownomics");

    int N, M;
    cin >> N >> M;
    
    vector<string> genomes(2*N);
    for (int i=0; i<2*N; i++) {
        cin >> genomes[i];
    }

    for (int i=0; i<2*N; i++) {
        cout << genomes[i] << ' ';
    }

    int spotty_genes = 0;
    vector<char> bases = {'A', 'T', 'C', 'G'} // adenine, thymine, cytosine, guanine
    for (int p=0; p<M; p++) {
        for (auto b : bases) {
            if ()
        }
    }
}