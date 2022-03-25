#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int kthElementIn2Sorted(
    vector<int>& nums1,
    vector<int>& nums2,
    int l, int r,
    int k
) {
    int cut1 = (l + r) / 2;
    int cut2 = k - cut1;

    int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

    int r1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
    int r2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];

    if (l1 <= r2 && l2 <= r1) {
        return max(l1, l2);
    } 

    if (l1 > r2) {
        return kthElementIn2Sorted(nums1, nums2, l, cut1 - 1, k);
    } else {
        return kthElementIn2Sorted(nums1, nums2, cut1 + 1, r, k);
    }
}

void solution()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    if (nums1.size() > nums2.size()) {
        cout << kthElementIn2Sorted(
            nums2, 
            nums1, 
            max(0, k - (int)nums1.size()),
            min(k, (int)nums2.size()), k) 
        << endl;
    } else {
        cout << kthElementIn2Sorted(
            nums1, 
            nums2, 
            max(0, k - (int)nums2.size()), 
            min(k, (int)nums1.size()), 
            k) 
        << endl;
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}