#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<char>> vv;

#define n 9

unordered_map<int, int> mapping;

bool Possible(vv& board, int row, int col, char x)
{
    for (int i = 0; i < n; i++) {
        if (board[row][i] == x) {
            return false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (board[i][col] == x) {
            return false;
        }
    }

    int rowIndex = row % 3, colIndex = col % 3;

    rowIndex = row + mapping[rowIndex];
    colIndex = col + mapping[colIndex];

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (board[rowIndex + i][colIndex + j] == x) {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vv& board, int row, int col, bool& ansFound)
{
    if (ansFound) {
        return;
    }

    if (row == n) {
        ansFound = true;
        return;
    }

    if (col == n) {
        solveSudoku(board, row + 1, 0, ansFound);
        return;
    }

    if (board[row][col] != '.') {
        solveSudoku(board, row, col + 1, ansFound);
        return;
    }

    for (char a = '1'; a <= '9'; a++) {
        if (Possible(board, row, col, a)) {
            board[row][col] = a;
            solveSudoku(board, row, col + 1, ansFound);

            if (ansFound) {
                return;
            }

            board[row][col] = '.';
        }
    }
}

void solution()
{
    vector<vector<char>> board(n);
    mapping[0] = 1;
    mapping[1] = 0;
    mapping[2] = -1;


    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a; 
            
            board[i].push_back(a);
        }
    }

    bool ansFound = false;

    solveSudoku(board, 0, 0, ansFound);

    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
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