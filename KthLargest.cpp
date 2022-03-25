#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int partition(vector<int>& nums, int l, int r)
{
    int index = l - 1;
    int pivot = nums[r];

    for (int i = l; i <= r - 1; i++) {
        if (nums[i] <= pivot) {
            index++;
            swap(nums[i], nums[index]);
        }
    }

    index++;
    swap(nums[index], nums[r]);

    return index;
}

int kthLargest(vector<int>& nums, int l, int r, int k)
{
    int index = partition(nums, l, r);

    int kFromLast = nums.size() - k;
    if (kFromLast == index) {
        return nums[index];
    }

    if (kFromLast > index) {
        return kthLargest(nums, index + 1, r, k);
    } else {
        return kthLargest(nums, l, index - 1, k);
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

    // int index = partition(nums, 0, nums.size() - 1);
    // for (int a: nums) {
    //     cout << a << " ";
    // }

    // cout << endl << index << endl;

    cout << kthLargest(nums, 0, nums.size() - 1, k) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}