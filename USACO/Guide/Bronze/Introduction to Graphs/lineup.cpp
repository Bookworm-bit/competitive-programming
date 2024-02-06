#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

void setIO(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int cowToNum(string cow) {
    return find(cows.begin(), cows.end(), cow) - cows.begin();
}

int main() {
    setIO("lineup");

    int N;
    cin >> N;

    map<string, vector<string>> adj;

    for (auto c : cows) {
        adj[c] = vector<string>();
    }

    map<string, bool> visited;
    for (int i=0; i<N; i++) {
        string a, b;
        string temp;
        cin >> a >> temp >> temp >> temp >> temp >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        visited[a] = false;
        visited[b] = false;
    }

    string ret = "";
    for (auto cow : adj) {
        if (cow.second.size() == 1 && !visited[cow.first]) {
            ret += " " + cow.first;
            visited[cow.first] = true;

            string temp = cow.second[0];

            while (adj[temp].size() == 2) {
                for (auto node : adj[temp]) {
                    if (!visited[node]) {
                        ret += " " + temp;
                        visited[temp] = true;
                        temp = node;
                    }
                }
            }

            ret += " " + temp;
            visited[temp] = true;
        } else if (cow.second.empty()) {
            ret += " " + cow.first;
        }
    }

    for (int i=1; i<ret.size(); i++) {
        if (ret[i] == ' ') cout << '\n';
        else cout << ret[i];
    }
}