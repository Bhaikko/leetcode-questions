#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int minCutsDP(string s)
{
    int n = s.size();

    vector<vector<bool>> palin(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, 9999));

    for (int gap = 0; gap < n; gap++) {
        for (int i = 0; i < n; i++) {
            if (i + gap >= n) {
                continue;
            }

            int j = i + gap;

            if (gap == 0) {
                palin[i][j] = true;
            } else if (gap == 1) {
                palin[i][j] = (s[i] == s[j]);
            } else {
                palin[i][j] = palin[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
    }

    for (int gap = 0; gap < n; gap++) {
        for (int i = 0; i < n; i++) {
            if (i + gap >= n) {
                continue;
            }

            int j = i + gap;

            if (gap == 0) {
                dp[i][j] = 0;
            } else if (gap == 1) {
                dp[i][j] = !(s[i] == s[j]);
            } else {
                if (palin[i][j]) {
                    dp[i][j] = 0;
                } else {
                    int col = i + 1;
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[i][k] + dp[col++][j]  
                        );
                    }
                    dp[i][j]++;
                }

            }
        }
    }

    // for (vector<int> a: dp) {
    //     for (int b: a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    return dp[0][n - 1];
}

int minCuts(string s, int index)
{
    if (s.size() == 2) {
        return !s[0] == s[1];
    } 

    if (s.size() <= 1) {
        return 0;
    }

    int n = s.size();

    if (isPalindrome(s)) {
        return 0;
    }
    // cout << index << endl;
    int cuts = INT_MAX;
    for (int cutsize = 1; cutsize <= n - 1; cutsize++) {
        
        int leftCut = 0;
        if (isPalindrome(s.substr(index, cutsize))) {
            leftCut = 0;
        } else {
            leftCut = minCuts(s.substr(index, cutsize), index);
        }

        int rightCut = 0;
        if (isPalindrome(s.substr(index + cutsize))) {
            rightCut = 0;
        } else {
            rightCut = minCuts(s.substr(index + cutsize), index + cutsize);
        }

        cuts = min(cuts, leftCut + rightCut + 1);
    }

    return cuts;
}

void solution()
{
    string s;
    cin >> s;

    cout << minCutsDP(s) << endl;

    // cout << minCuts(s, 0) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}