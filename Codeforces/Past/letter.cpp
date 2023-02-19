#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> lines(n);

    int start_x = 10000;
    int start_y = 10000;
    int end_x = 0;
    int end_y = 0;

    for (int i=0; i<n; i++) {
        cin >> lines[i];
    }

    string current_line;
    int j;
    for (int i=0; i<n; i++) {
        current_line = lines[i];
        if (current_line.find('*') != string::npos) {
            j = current_line.find('*'); 
            start_x = min(start_x, j);
            start_y = min(start_y, i);
            end_x = max(end_x, j);
            end_y = max(end_y, i);
        }
    }

    for (int i=start_y; i<end_y+1; i++) {
        current_line = lines[i];
        cout << current_line[start_x] << '\n';
    }
}