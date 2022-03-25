#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int BurstBallon(int arr[], int n)
{
    int dp[n][n];

    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            int maxValue = INT_MIN;

            for (int k = i; k <= j; k++) {
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];

                int val = (
                    (i == 0     ? 1 : arr[i - 1]) *
                    (arr[k]) * 
                    (j == n - 1 ? 1 : arr[j + 1])
                );

                int total = left + right + val;
                maxValue = max(total, maxValue);
            }

            dp[i][j] = maxValue;
        }
    }

    return dp[0][n - 1];
}

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << BurstBallon(arr, n) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}