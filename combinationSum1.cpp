#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void combinationSums(
    vector<int>& nums, 
    int target,
    int current,
    vector<int> possibleArray,
    vector<vector<int>>& answers
) {
    if (current >= nums.size()) {
        return;
    }

    if (target < 0) {
        return;
    }

    if (target == 0) {
        answers.push_back(possibleArray);
        return;
    }

    // Not considering
    combinationSums(nums, target, current + 1, possibleArray, answers);

    // Considering
    possibleArray.push_back(nums[current]);
    combinationSums(nums, target - nums[current], current, possibleArray, answers);
}

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    vector<vector<int>> answers;
    vector<int> possible;

    combinationSums(nums, k, 0, possible, answers);

    cout << answers.size() << endl;

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