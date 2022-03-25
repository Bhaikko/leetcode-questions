#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void fillLeftSmaller(vector<int>& nums, vector<int>& leftSmaller)
{
    int n = nums.size();

    // Stores indexes
    stack<int> smaller;

    for (int i = 0; i < n; i++) {
        if (!smaller.empty() && nums[smaller.top()] < nums[i]) {
            leftSmaller[i] = smaller.top() + 1;
        } else {
            while (!smaller.empty() && nums[smaller.top()] >= nums[i]) {
                smaller.pop();
            }

            leftSmaller[i] = smaller.empty() ? 0 : smaller.top() + 1;
        }

        smaller.push(i);
    }
}

void fillRightSmaller(vector<int>& nums, vector<int>& rightSmaller)
{
    int n = nums.size();

    // Stores indexes
    stack<int> smaller;

    for (int i = n - 1; i >= 0; i--) {
        if (!smaller.empty() && nums[smaller.top()] < nums[i]) {
            rightSmaller[i] = smaller.top() - 1;
        } else {
            while (!smaller.empty() && nums[smaller.top()] >= nums[i]) {
                smaller.pop();
            }

            rightSmaller[i] = smaller.empty() ? n - 1 : smaller.top() - 1;
        }

        smaller.push(i);
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

    vector<int> leftSmaller(n, 0), rightSmaller(n, n);

    fillLeftSmaller(nums, leftSmaller);
    fillRightSmaller(nums, rightSmaller);

    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = rightSmaller[i] - leftSmaller[i] + 1;
        maxArea = max(maxArea, width * nums[i]);
    }

    cout << maxArea << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}