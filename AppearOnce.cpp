#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int singleNumber(vector<int>& arr, int l, int r)
{
    if (l > r) {
        return l;
    }

    int mid = (l + r) / 2;

    if (mid & 1) {
        // Odd Index
        if (arr[mid] == arr[mid + 1]) {
            // First Instance
            // Right Half -> Search in Left Half
            return singleNumber(arr, l, mid - 1);
        } else {
            // Second Instance
            // Left Half -> search in right half
            return singleNumber(arr, mid + 1, r);
        }
    } else {
        // Even index
        if (arr[mid] == arr[mid + 1]) {
            // First instance
            // Left half -> search in right half
            return singleNumber(arr, mid + 1, r);
        } else {
            // Second Instance
            // Right half -> search in left half
            return singleNumber(arr, l, mid - 1);
        }
    }
}

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << arr[singleNumber(arr, 0, arr.size() - 2)] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}