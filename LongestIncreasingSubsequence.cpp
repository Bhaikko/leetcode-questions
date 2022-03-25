#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int lisDP(vector<int>& nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (nums[j] > nums[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}

// DFS without memoization
int lis(
    vector<int>& nums, 
    int index, 
    vector<int> currentSeq,
    unordered_map<int, int>& occured
) {
    // if (occured.find(index) != occured.end()) {
    //     return occured[index];
    // }

    if (index == nums.size()) {
        return currentSeq.size();
    }

    int ans = currentSeq.size();

    for (int i = index; i < nums.size(); i++) {
        if (
            currentSeq.size() == 0 || 
            currentSeq[currentSeq.size() - 1] < nums[i]
        ) {
            currentSeq.push_back(nums[i]);
            ans = max(ans, lis(nums, i + 1, currentSeq, occured));
            currentSeq.pop_back();
        } 
    }

    // occured[index] = ans;

    return ans;
}

void solution()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> occured;

    // cout << lis(nums, 0, vector<int>(), occured) << endl;
    cout << lisDP(nums) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}