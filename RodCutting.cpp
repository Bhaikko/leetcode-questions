#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[1][i] = i * costs[0];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int taken = 0;
            int lenToCut = i;
            if (j - lenToCut >= 0) {
                taken = dp[i][j - lenToCut] + costs[i - 1];
            }

            int nottaken = dp[i - 1][j];

            dp[i][j] = max(taken, nottaken);
        }
    }

    cout << dp[n][n] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}