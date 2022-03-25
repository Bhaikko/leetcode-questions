#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string s;
    cin >> s;

    int n = s.size();
    
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int gap = 1; gap <= n; gap++) {
        for (int i = 0; i < n; i++) {
            if (i + gap >= n) {
                continue;
            }

            if (s[i] == s[i + gap]) {
                if (gap == 1) {
                    dp[i][i + gap] = 2;
                } else {
                    dp[i][i + gap] = dp[i + 1][i + gap - 1] + 2;
                }
            } else {
                dp[i][i + gap] = max(dp[i][i + gap - 1], dp[i + 1][i + gap]);
            }
        }
    }

    cout << s.size() - dp[0][n - 1] << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}