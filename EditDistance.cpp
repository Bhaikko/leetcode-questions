#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int editDistanceDP(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(
                    min(dp[i - 1][j], dp[i][j - 1]),
                    dp[i - 1][j - 1]
                );
            }

        }
    }

    return dp[n][m];

}

int editDistance(string word1, string word2)
{
    if (word1 == "") {
        return word2.size();
    }

    if (word2 == "") {
        return word1.size();
    }

    if (word1[0] == word2[0]) {
        return editDistance(word1.substr(1), word2.substr(1));
    } 

    int insertOp = editDistance(word2[0] + word1, word2);
    int deleteOp = editDistance(word1.substr(1), word2);
    int replaceOp = editDistance(word2[0] + word1.substr(1), word2);

    return 1 + min(min(insertOp, deleteOp), replaceOp);
    
}

void solution()
{
    string word1, word2;
    cin >> word1 >> word2;

    if (word1.size() > word2.size()) {
        swap(word1, word2);
    }

    cout << editDistance(word1, word2) << endl;
    cout << editDistanceDP(word1, word2) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}