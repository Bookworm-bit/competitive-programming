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

	vector<vector<string>> genomes(2);
	for (int i=0; i<2; i++) {
		vector<string> genome(N);
		for (int j=0; j<N; j++) {
			cin >> genome[j];
		}
		genomes[i] = genome;
	}

    int c = 0;
	for (int i=0; i<M; i++) {
		for (int j=i+1; j<M; j++) {
			for (int k=j+1; k<M; k++) {
                set<string> spotty;
	            set<string> plain;
				for (int l=0; l<N; l++) {
					string spottyCombo;
					spottyCombo += genomes[0][l][i];
					spottyCombo += genomes[0][l][j];
					spottyCombo += genomes[0][l][k];

					string plainCombo;
					plainCombo += genomes[1][l][i];
					plainCombo += genomes[1][l][j]; 
					plainCombo += genomes[1][l][k];

					spotty.insert(spottyCombo);
					plain.insert(plainCombo);
				}

                vector<string> intersection;
                set_intersection(spotty.begin(), spotty.end(), plain.begin(), plain.end(), back_inserter(intersection));

                if (intersection.size() == 0) { c++; }
			}
		}
	}

	cout << c << '\n';
}