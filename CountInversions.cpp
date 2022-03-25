#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Merge(int arr[], int l, int mid, int r, int merge[])
{
    int inversions = 0;

    int i = l,
        j = mid + 1,
        k = 0;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            merge[k++] = arr[i++];
            
        } else {
            inversions += (mid - i + 1);
            merge[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        merge[k++] = arr[i++];
    }

    while (j <= r) {
        merge[k++] = arr[j++];
    }

    return inversions;
}

int CountInversions(int arr[], int l, int r)
{
    if (r <= l) {
        return 0;
    }

    int mid = (l + r) / 2;

    int leftInv = CountInversions(arr, l, mid);
    int rightInv = CountInversions(arr, mid + 1, r);

    int merge[r - l + 1];

    int currInv = Merge(arr, l, mid, r, merge);

    int k = 0;
    for (int i = l; i <= r; i++) {
        arr[i] = merge[k++];
    }

    return leftInv + rightInv + currInv;
}

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << CountInversions(arr, 0, n - 1) << endl; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}