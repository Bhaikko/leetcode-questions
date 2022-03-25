#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(
    vector<vector<char>>& grid,
    int m, int n,
    int r, int c 
) {
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '2' || grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '2';

    dfs(grid, m, n, r + 1, c);
    dfs(grid, m, n, r - 1, c);
    dfs(grid, m, n, r, c + 1);
    dfs(grid, m, n, r, c - 1);
}

void solution()
{
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n, '0'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                cout << i << j << endl;
                dfs(grid, m, n, i, j);
                count++;
            }
        }
    }

    for (auto a: grid) {
        for (char b: a) {
            cout << b << " ";
        }
        cout << endl;
    }

    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}