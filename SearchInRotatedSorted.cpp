#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int searchIn_K_Sorted(vector<int>& arr, int l, int r, int k)
{
    if (l > r) {
        return -1;
    }

    int mid = (l + r) / 2;
    if (arr[mid] == k) {
        return mid;
    }

    if (arr[l] <= arr[mid]) {
        // Left half sorted
        // Left half check
        if (arr[l] <= k && k <= arr[mid]) {
            return searchIn_K_Sorted(arr, l, mid - 1, k);
        } else {
            return searchIn_K_Sorted(arr, mid + 1, r, k);
        }
    } else {
        if (arr[mid] <= k && k <= arr[r]) {
            return searchIn_K_Sorted(arr, mid + 1, r, k);
        } else {
            return searchIn_K_Sorted(arr, l, mid - 1, k);
        }
    }
} 

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << searchIn_K_Sorted(arr, 0, n - 1, k) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}