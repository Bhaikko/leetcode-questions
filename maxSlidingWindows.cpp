#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> fillNextGreater(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nextGreater(nums.size(), INT_MIN);

    stack<int> indexes;

    for (int i = n - 1; i >= 0; i--) {
        if (!indexes.empty() && nums[indexes.top()] > nums[i]) {
            nextGreater[i] = indexes.top();
        } else {
            while (!indexes.empty() && nums[indexes.top()] <= nums[i]) {
                indexes.pop();
            }

            nextGreater[i] = indexes.empty() ? INT_MIN : indexes.top();
        }

        indexes.push(i);
    }

    return nextGreater;
}

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> nextGreater = fillNextGreater(nums);

    int i, j = 0;
    for (int i = 0; i < k; i++) {
        if (nums[j] < nums[i]) {
            j = i;
        }
    }

    for (int i = 1; i <= n - k; i++) {
        cout << nums[j] << " ";

        if (j < i) {
            j = i;
        }

        while (true) {
            int windowEnd = i + k - 1;

            if (nextGreater[j] > windowEnd || nextGreater[j] == INT_MIN) {
                break;
            }

            j = nextGreater[j];
        }
    }

    cout << nums[j] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}