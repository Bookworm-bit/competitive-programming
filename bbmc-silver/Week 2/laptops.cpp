#include <bits/stdc++.h>
using namespace std;

string check_sorted(vector<int> a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            return "Happy ";
        }
    }
    return "Poor ";
}

int main() {
    int N;
    cin >> N;

    map<int, int> priceToQuality;

    for (int i=0; i<N; i++) {
		int price, quality;
		cin >> price >> quality;
        priceToQuality[price] = quality;
    }

	vector<int> qualities;
	for (const auto& pair : priceToQuality) {
		qualities.push_back(pair.second);
	}

    cout << check_sorted(qualities, N) << "Alex" << '\n';
}
