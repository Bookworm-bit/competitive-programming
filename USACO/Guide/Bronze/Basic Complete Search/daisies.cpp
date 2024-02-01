#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<int> daisies(N);
    for (int i=0; i<N; i++) {
        cin >> daisies[i];
    }

    int average_flower = 0;
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {    
            vector<int> daisy_section(daisies.begin()+i, daisies.begin()+j+1);
            double petal_avg = 0;
            for (int k=0; k<daisy_section.size(); k++) {
                petal_avg += (double) daisy_section[k];
            }
            petal_avg /= daisy_section.size();
            for (int k=0; k<daisy_section.size(); k++) {
                if ((double) daisy_section[k] == petal_avg) {
                    average_flower++;
                    break;
                }
            }
        }
    }
    cout << average_flower << '\n';
}