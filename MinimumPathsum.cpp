#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxPathDP(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[m - 1][n - 1] = grid[m - 1][n - 1];

    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        dp[m - 1][i] = dp[m - 1][i + 1] + grid[m - 1][i];
    }

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
    }

    return dp[0][0];
}

string GetKey(int i, int j)
{
    return to_string(i) + "," + to_string(j);
}

int maxPath(
    vector<vector<int>>& grid,
    int m, int n,
    int i, int j,
    unordered_map<string, int>& occured
) {
    if (occured.find(GetKey(i, j)) != occured.end()) {
        return occured[GetKey(i, j)];
    }

    if (i >= m || j >= n) {
        return INT_MAX;
    }

    if (i == m - 1 && j == n - 1) {
        return grid[i][j];
    }

    int rightPath = maxPath(grid, m, n, i + 1, j, occured);
    int bottomPath = maxPath(grid, m, n, i, j + 1, occured);

    occured[GetKey(i, j)] = min(rightPath, bottomPath) + grid[i][j];

    return occured[GetKey(i, j)];
}

void maxPathBrute(
    vector<vector<int>>& grid, 
    int m,
    int n,
    int i, 
    int j,
    int currSum,
    int& minPathSum
) {
    
    if (i >= m || j >= n) {
        return;
    }

    if (i == m - 1 && j == n - 1) {
        minPathSum = min(currSum + grid[i][j], minPathSum);
    }

    maxPathBrute(grid, m, n, i + 1, j, currSum + grid[i][j], minPathSum);
    maxPathBrute(grid, m, n, i, j + 1, currSum + grid[i][j], minPathSum);
}

void solution()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // int minPathSum = INT_MAX;
    // maxPathBrute(grid, m, n, 0, 0, 0, minPathSum);

    // cout << minPathSum << endl;

    // unordered_map<string, int> occured;
    // cout << maxPath(grid, m, n, 0, 0, occured) << endl;

    cout << maxPathDP(grid) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}