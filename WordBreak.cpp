#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool wordBreak(string s, vector<string>& dict)
{
    int n = s.size();
    vector<int> dp(n + 1, false);

    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (string tomatch: dict) {
            if (i + tomatch.size() <= s.size()) {
                string substring = s.substr(i, tomatch.size());
                    
                if (substring == tomatch) {
                    dp[i] = dp[i + tomatch.size()];
                }

                if (dp[i]) {
                    break;
                }
            }
        }
        
    }

    return dp[0];

}

bool wordBreak(
    string s, 
    vector<string>& dict, 
    int index,
    unordered_map<int, bool>& dp
) {
    if (dp.find(index) != dp.end()) {
        return dp[index];
    }

    if (index == s.size()) {
        dp[index] = true;
        return true;
    }

    for (int i = 0; i < dict.size(); i++) {
        string toMatch = dict[i];
        string substring = s.substr(index, toMatch.size());

        if (toMatch == substring) {
            if (wordBreak(s, dict, index + toMatch.size(), dp)) {
                dp[index + toMatch.size()] = true;
                return true;
            }
        }
    }

    dp[index] = false;

    return false;
}

void solution()
{
    string s;
    int n;
    cin >> s >> n;

    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
    }

    unordered_map<int, bool> dp;

    // cout << wordBreak(s, dict, 0, dp) << endl;
    cout << wordBreak(s, dict) << endl;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}