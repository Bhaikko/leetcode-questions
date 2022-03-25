#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double medianOfTwoSorted(
    vector<int>& nums1, 
    vector<int>& nums2, 
    int l,
    int r
) {
    int cut1 = (l + r) / 2;
    int cut2 = (nums1.size() + nums2.size() + 1) / 2 - cut1;

    // cout << cut1 << " " << cut2 << endl;

    int l1 = cut1 <= 0 ? INT_MIN : nums1[cut1 - 1];
    int l2 = cut2 <= 0 ? INT_MIN : nums2[cut2 - 1];

    int r1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
    int r2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];

    if (l1 <= r2 && l2 <= r1) {
        // cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl; 
        if ((nums1.size() + nums2.size()) & 1) {
            return max(l1, l2);
        } else {
            return (
                max(l1, l2) + min(r1, r2)
            ) / 2.0f;   
        }
    } 

    if (l1 > r2) {
        return medianOfTwoSorted(nums1, nums2, l, cut1 - 1);
    } else {
        return medianOfTwoSorted(nums1, nums2, cut1 + 1, r);
    } 
}

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    cout << ((nums1.size() <= nums2.size()) ? 
            medianOfTwoSorted(nums1, nums2, 0, nums1.size()) :
            medianOfTwoSorted(nums2, nums1, 0, nums2.size())) << endl;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}