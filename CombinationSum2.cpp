#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void combinationSum(
    vector<int>& nums,
    int current,
    int n,
    int target,
    vector<int> prev,
    vector<vector<int>>& answers
) {
    if (target == 0) {
        // prev.push_back(nums[current]);
        answers.push_back(prev);
        return;
    }

    if (target < 0) {
        return;
    }

    if (current == n) {
        return;
    }

    int lastElPicked = -1;
    for (int i = current; i < n; i++) {
        if (lastElPicked != nums[i]) {
            lastElPicked = nums[i];

            prev.push_back(nums[i]);
            combinationSum(nums, i + 1, n, target - nums[i], prev, answers);
            prev.pop_back();
        }
    }
}

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> answers;
    vector<int> prev;

    sort(nums.begin(), nums.end());

    combinationSum(nums, 0, n, k, prev, answers);

    for (vector<int> a: answers) {
        for (int b: a) {
            cout << b << " ";
        } 
        cout << endl;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}