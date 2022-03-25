#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(
    vector<vector<int>>& grid, 
    int row, int col,
    int m, int n,
    int& count
) {
    if (
        row < 0 || row >= m || col < 0 || col >= n ||
        grid[row][col] == 0 || grid[row][col] == 2
    ) {
        return;
    }

    grid[row][col] = 2;
    count++;

    for (int i = col + 1; i < n; i++) {
        if (grid[row][i] == 1) {
            dfs(grid, row, i, m, n, count);
        }
    }

    for (int i = row + 1; i < m; i++) {
        if (grid[i][col] == 1) {
            dfs(grid, i, col, m, n, count);
        }
    }

    for (int i = col - 1; i >= 0; i--) {
        if (grid[row][i] == 1) {
            dfs(grid, row, i, m, n, count);
        }
    }

    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 1) {
            dfs(grid, i, col, m, n, count);
        }
    }
}

void solution()
{
    int m, n;
    cin >> m >> n;

    int ans = 0;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int count = 0;
                cout << i << " " << j << endl;
                dfs(grid, i, j, m, n, count);

                if (count > 1) {
                    ans += count;
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}