#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> permute(vector<int>& nums, int index)
{
    if (index == nums.size() - 1) {
        vector<int> per(1, nums[index]);
        return vector<vector<int>>(1, per);
    }

    vector<vector<int>> prevPremute = permute(nums, index + 1);
    vector<vector<int>> newpermutations;

    int currentNum = nums[index];

    for (vector<int> arr: prevPremute) {

        for (int k = 0; k <= arr.size(); k++) {
            vector<int> newper;
            for (int i = 0; i < arr.size(); i++) {
                if (i == k) {
                    newper.push_back(currentNum);
                }

                newper.push_back(arr[i]);
            }

            if (k == arr.size()) {
                newper.push_back(currentNum);
            }

            newpermutations.push_back(newper);
        }
    }

    return newpermutations;
}

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> answer = permute(arr, 0);

    for (vector<int> a: answer) {
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