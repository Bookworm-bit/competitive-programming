#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int areaOfIntersection(int board[2][2], int truck[2][2]) {
    if (board[1][1] <= truck[0][1] || board[0][1] >= truck[1][1] || board[0][0] >= truck[1][0] || board[1][0] <= truck[0][0]) {
        return 0;
    }

    int width = min(board[1][0], truck[1][0]) - max(board[0][0], truck[0][0]);
    int height = min(board[1][1], truck[1][1]) - max(board[0][1], truck[0][1]);

    return width * height;
}

int main() {
    setIO("billboard");
    
    int billboard1[2][2];
    int billboard2[2][2];
    int truck[2][2];

    // billboard[0] is BL, billboard[1] is TR
    cin >> billboard1[0][0] >> billboard1[0][1] >> billboard1[1][0] >> billboard1[1][1];
    cin >> billboard2[0][0] >> billboard2[0][1] >> billboard2[1][0] >> billboard2[1][1];
    cin >> truck[0][0] >> truck[0][1] >> truck[1][0] >> truck[1][1];

    int b1width = billboard1[1][0] - billboard1[0][0];
    int b1height = billboard1[1][1] - billboard1[0][1];
    int b1area = b1width * b1height;

    int b2width = billboard2[1][0] - billboard2[0][0];
    int b2height = billboard2[1][1] - billboard2[0][1];
    int b2area = b2width * b2height;

    int b1truck = areaOfIntersection(billboard1, truck);
    int b2truck = areaOfIntersection(billboard2, truck);

    int total = b1area + b2area - b1truck - b2truck;

    cout << total << '\n';
}