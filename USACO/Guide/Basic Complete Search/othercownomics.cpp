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
    
    vector<char> bases = {'A', 'T', 'C', 'G'};
    vector<string> genomes(2*N);
    for (int i=0; i<2*N; i++) {
        cin >> genomes[i];
    }

    int spotty_genes = 0;
    for (int p=0; p<M; p++) {
        string spotty = "";
        string plain = "";
        for (int c=0; c<N; c++) {
            spotty += genomes[c][p];
        }
        for (int c=N; c<2*N; c++) {
            plain += genomes[c][p];
        }

        for (auto c : )
    }
    cout << spotty_genes << '\n';
}