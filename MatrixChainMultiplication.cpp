#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int numMatrices = n - 1;

    vector<pp> matrices(numMatrices, pp());
    for (int i = 0; i < numMatrices; i++) {
        matrices[i].first = arr[i];
        matrices[i].second = arr[i + 1];
    }

    vector<vector<int>> dp(numMatrices, vector<int>(numMatrices, 0));

    for (int gap = 1; gap < numMatrices; gap++) {
        for (int i = 0; i < numMatrices; i++) {
            if (i + gap >= numMatrices) {
                continue;
            }

            int j = i + gap;
            if (gap == 1) {
                dp[i][j] = matrices[i].first * matrices[i].second * matrices[j].second;
                continue;
            }

            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {

                dp[i][j] = min((
                    dp[i][k] + dp[k + 1][j] +
                    matrices[i].first * matrices[k].second * matrices[j].second
                ), dp[i][j]);
            }
        }
    }

    cout << dp[0][numMatrices - 1] << endl;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}