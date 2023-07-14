#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() { 
    setIO("notlast");

    int N;
    cin >> N;

    vector<string> cows;
    vector<int> production;
    for (int i=0; i<N; i++) {
        string name;
        int milk;

        cin >> name >> milk;

        if (count(cows.begin(), cows.end(), name) > 0) {
            production[find(cows.begin(), cows.end(), name) - cows.begin()] += milk; 
        } else {
            cows.push_back(name);
            production.push_back(milk);
        }
    }

    int smallest = *min_element(production.begin(), production.end());

    if (cows.size() < 7) {
        smallest = 0;
    }

    int secondSmallest = INT32_MAX;

    int c = 0;
    for (int i=0; i<cows.size(); i++) {
        if (production[i] > smallest) {
            secondSmallest = min(secondSmallest, production[i]);
            c++;
        }
    }

    if (c == 0 || count(production.begin(), production.end(), secondSmallest) > 1) {
        cout << "Tie" << '\n';
    } else {
        cout << cows[find(production.begin(), production.end(), secondSmallest) - production.begin()] << '\n';
    }
}
