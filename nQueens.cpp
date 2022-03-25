#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<string>> vvs;

bool canPlace(int row, int col, int n, vector<string> board)
{
    // Checking Row
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Checking Col
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Checking diagonals
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }

        i--; j--;
    }

    i = row, j = col;
    while (i < n && j < n) {
        if (board[i][j] == 'Q') {
            return false;
        }

        i++; j++;
    }

    i = row, j = col;
    while (i >= 0 && j < n) {
        if (board[i][j] == 'Q') {
            return false;
        }

        i--; j++;
    }

    i = row, j = col;
    while (i < n && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }

        i++; j--;
    }

    return true;
}

void nQueens(int n, int col, vector<string> board, int& ways, vvs& boards)
{
    if (col >= n) {
        ways++;
        boards.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (canPlace(i, col, n, board)) {
            board[i][col] = 'Q';
            nQueens(n, col + 1, board, ways, boards);
            board[i][col] = '.';
        }
    }
}

void solution()
{
    int n;
    cin >> n;

    int ways = 0;
    vvs boards;
    for (int i = 0; i < n; i++) {
        string row = "";
        for (int i = 0; i < n; i++) {
            row += ".";
        }

        vector<string> board(n, row);

        board[i][0] = 'Q';

        nQueens(n, 1, board, ways, boards);
    }

    cout << ways << endl;

    for (int i = 0; i < boards.size(); i++) {
        for (int j = 0; j < boards[i].size(); j++) {
            cout << boards[i][j] << endl;
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}