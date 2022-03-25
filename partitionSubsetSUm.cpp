#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum & 1) {
        cout << "false" << endl;
    } else {
        set<int> sums;
        int target = sum / 2;

        sums.insert(0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp;
            for (auto curr: sums) {
                temp.push_back(curr + nums[i]);
            }

            for (int a: temp) {
                sums.insert(a);
            }
        }

        if (sums.find(target) == sums.end()) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}