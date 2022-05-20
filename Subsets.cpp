#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> subsets(vector<int>& nums, int index)
{
    if (index == nums.size()) {
        return vector<vector<int>>(1, vector<int>());
    }

    vector<vector<int>> oldSubsets = subsets(nums, index + 1);

    int currentEle = nums[index];
    vector<vector<int>> newSubsets = oldSubsets;
    int num = newSubsets.size();

    for (int i = 0; i < num; i++) {
        vector<int> newSubset;
        newSubset.push_back(currentEle);

        for (int a: newSubsets[i]) {
            newSubset.push_back(a);
        }

        newSubsets.push_back(newSubset);
    }

    return newSubsets;
}

void solution()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> subsetsAns = subsets(nums, 0);

    for (auto a: subsetsAns) {
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