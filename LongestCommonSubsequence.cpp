#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int lcs_dp(string& test1, string& test2)
{
    int n = test1.size(),
        m = test2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (test1[i - 1] == test2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    return dp[n][m];
}

int lcs(string& test1, string& test2, int index1, int index2)
{
    if (index1 == test1.size() || index2 == test2.size()) {
        return 0;
    }

    if (test1[index1] == test2[index2]) {
        return 1 + lcs(test1, test2, index1 + 1, index2 + 1);
    }

    return max(
        lcs(test1, test2, index1 + 1, index2),
        lcs(test1, test2, index1, index2 + 1)
    );
}

void solution()
{
    string text1, text2;
    cin >> text1 >> text2;

    cout << lcs(text1, text2, 0, 0) << endl;
    cout << lcs_dp(text1, text2) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}