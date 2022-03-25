#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int coinChange(vector<int>& coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            dp[coins[i]] = 1;
        }
    }

    for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
        for (int i = 0; i < n; i++) {
            if (
                currentAmount >= coins[i] && 
                dp[currentAmount - coins[i]] != INT_MAX
            ) {
                dp[currentAmount] = min(
                    1 + dp[currentAmount - coins[i]], 
                    dp[currentAmount]
                );
            }
        }
    }

    return dp[amount];
}

void coinChange(
    vector<int>& arr,
    int index, 
    int n, 
    int amount,
    int currentCount,
    int& count
) {
    if (amount < 0) {
        return;
    }

    if (amount == 0) {
        count = min(currentCount, count);
    }

    for (int i = index; i < n; i++) {
        coinChange(arr, i, n, amount - arr[i], currentCount + 1, count);
    }
}

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = INT_MAX;
    coinChange(arr, 0, n, k, 0, count);

    cout << count << endl;
    
    cout << coinChange(arr, k) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}