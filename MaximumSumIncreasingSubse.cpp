#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int maxSumDP(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
        dp[i] = nums[i];
    }

    int ans = dp[0];

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << endl;
    for (int a: dp) {
        cout << a << " ";
    }
    cout << endl;

    return ans;

}

int maxSum(
    vector<int>& nums, 
    int index, 
    vector<int> seq, 
    int sumTillNow, 
    int k,
    int& ans
) {
    
    if (seq.size() == k) {
        ans = max(ans, sumTillNow);
    }

    if (index == nums.size()) {
        return -1;
    }

    int maxSumTillNow = sumTillNow;

    
    for (int i = index; i < nums.size(); i++) {
        if (
            seq.size() == 0 ||
            seq[seq.size() - 1] < nums[i]   
        ) {
            seq.push_back(nums[i]);
            maxSumTillNow = max(maxSumTillNow, sumTillNow + nums[i]);

            maxSum(nums, i + 1, seq, sumTillNow + nums[i], k, ans);
            seq.pop_back();
        }
    }

    return maxSumTillNow;

}

void solution()
{
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    // int ans = -1;
    // maxSum(
    //     nums,
    //     0,
    //     vector<int>(),
    //     0,
    //     k,
    //     ans
    // );
    // cout << ans << endl;

    cout << maxSumDP(nums, k) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}