#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

string setToString(set<char> c) {
    string s = "";
    for (char ch : c) {
        s += ch;
    }
    return s;
}

int main() {
    setIO("tttt");

    char board[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> board[i][j];
        }
    }

    set<char> singleCow;
    set<string> teamCow;

    // rows
    for (int i=0; i<3; i++) {
        set<char> rowSet;

        for (int j=0; j<3; j++) {
            rowSet.insert(board[i][j]);
        }

        if (rowSet.size() == 1) {
            singleCow.insert(board[i][0]);
        } else if (rowSet.size() == 2) {
            teamCow.insert(setToString(rowSet));
        }
    }

    // columns
    for (int j=0; j<3; j++) {
        set<char> colSet;

        for (int i=0; i<3; i++) {
            colSet.insert(board[i][j]);
        }

        if (colSet.size() == 1) {
            singleCow.insert(board[0][j]);
        } else if (colSet.size() == 2) {
            teamCow.insert(setToString(colSet));
        }
    }

    // TL to BR diagonal
    set<char> diagSet;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == j) {
                diagSet.insert(board[i][j]);
            }
        }
    }

    if (diagSet.size() == 1) {
        singleCow.insert(board[0][0]);
    } else if (diagSet.size() == 2) {
        teamCow.insert(setToString(diagSet));
    }

    // TR to BL diagonal
    diagSet.clear();
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i + j == 2) {
                diagSet.insert(board[i][j]);
            }
        }
    }

    if (diagSet.size() == 1) {
        singleCow.insert(board[0][0]);
    } else if (diagSet.size() == 2) {
        teamCow.insert(setToString(diagSet));
    }

    cout << singleCow.size() << '\n';
    cout << teamCow.size() << '\n';
}