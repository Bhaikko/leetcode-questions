#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int knapsackDPspace(vector<int>& weights, vector<int>& values, int weight)
{
    int n = weights.size();

    vector<int> dp(weight + 1, 0), temp(weight + 1, 0);
    int objNumber = 1;

    for (int i = 1; i <= n; i++) {
        temp = dp;
        
        for (int j = 1; j <= weight; j++) {
            int taken = 0;
            if (j - weights[i - 1] >= 0) {
                taken = dp[j - weights[i - 1]] + values[i - 1];
            }

            int nottaken = dp[j];

            temp[j] = max(taken, nottaken);

        }

        dp = temp;
    }

    return dp[weight];
}

int knapsackDP(vector<int>& weights, vector<int>& values, int weight)
{
    int n = weights.size();

    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

    for (int i = 0; i <= weight; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= weight; j++) {
            int taken = 0;
            if (j - weights[i - 1] >= 0) {
                taken = dp[i - 1][j - weights[i - 1]] + values[i - 1];
            }

            int notTaken = dp[i - 1][j];

            dp[i][j] = max(taken, notTaken);
        }
    }

    return dp[n][weight];

}

int knapsack(vector<int>& weights, vector<int>& values, int index, int weight)
{
    if (index == weights.size()) {
        return 0;
    }

    int taken = -1;
    
    if (weights[index] <= weight) {
        taken = knapsack(weights, values, index + 1, weight - weights[index]) + values[index];
    }
        
    int nottaken = knapsack(weights, values, index + 1, weight);

    return max(
        taken, nottaken
    );
}

void solution()
{
    int n, w;
    cin >> n;

    vector<int> weights(n),
                values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }   

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cin >> w;

    // cout << knapsack(weights, values, 0, w) << endl;
    cout << knapsackDPspace(weights, values, w) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}