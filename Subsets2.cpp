#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void subsetsWithDup(
    vector<int>& nums,
    int current,
    int n,
    vector<int> prev,
    vector<vector<int>>& answers
) {
    answers.push_back(prev);
    if (current == n) {
        return;
    }

    int lastEl = -11;
    for (int i = current; i < n; i++) {
        if (lastEl != nums[i]) {
            lastEl = nums[i];

            prev.push_back(nums[i]);
            subsetsWithDup(nums, i + 1, n, prev, answers);
            prev.clear();
        }
    }

}

void solution()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> answers;
    vector<int> prev;

    sort(nums.begin(), nums.end());

    subsetsWithDup(nums, 0, n, prev, answers);

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