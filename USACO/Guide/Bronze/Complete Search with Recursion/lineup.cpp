#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("lineup");

	int N;
	cin >> N;

	vector<pair<string, string>> restrictions(N);
	for (int i=0; i<N; i++) {
		string x, y, temp;
		cin >> x >> temp >> temp >> temp >> temp >> y;

		restrictions[i] = make_pair(x, y);
	}

	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	string nums = "01234567";
	vector<string> orientations;
	do {
		string temp;
		for (auto e : nums) {
			temp += cows[e - '0'];
		}
		orientations.push_back(temp);
	} while (next_permutation(nums.begin(), nums.end()));

	set<string> ans;
	for (auto o : orientations) {
		bool possible = true;
		for (auto r : restrictions) {
			string temp1 = r.first + r.second;
			string temp2 = r.second + r.first;

			if (o.find(temp1) == string::npos && o.find(temp2) == string::npos) {
				possible = false;
				break;
			} 
		}
		

		if (possible) {
			ans.insert(o); 
		}
	}

	for (auto v : ans) {
		for (int i=0; i<v.size(); i++) {
			if (v[i] - 'a' < 0 && i != 0) {
				cout << '\n';
			}
			cout << v[i];
		}
		break;
	}
	cout << '\n';
}