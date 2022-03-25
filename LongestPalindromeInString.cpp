#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // gap Strats
    for (int gap = 1; gap <= n; gap++) {
        for (int i = 0; i < n; i++) {
            if (i + gap) {
                if (s[i] == s[i + gap]) {
                    if (gap == 1) {
                        dp[i][i + gap] = true; 
                    } else {
                        dp[i][i + gap] = dp[i + 1][i + gap - 1];
                    }
                } else {
                    dp[i][i + gap] = false;
                }
            }
        }
    }

    int maxGap = 0;
    int maxGapL, maxGapR;

    // for (vector<bool> a: dp) {
    //     for (bool b: a) {
    //         cout << b << " ";
    //     }

    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (dp[i][j]) {
                int gap = j - i;
                if (gap >= maxGap) {
                    maxGapL = i;
                    maxGapR = j;
                    maxGap = gap;
                }
            }
        }
    }

    cout << maxGapL << " " << maxGapR << endl;

    cout << s.substr(maxGapL, maxGapR - maxGapL + 1) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}