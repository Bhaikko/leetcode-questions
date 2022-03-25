#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int CheckInSize3(int arr[], int i, int j)
{
    if (i == j) {
        // Size 1
        return arr[i];
    }

    // Size 3
    if (arr[0] == arr[1]) {
        return arr[2];
    } else {
        return arr[0];
    }
}

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int i = 0, j = n - 1;
    int mid;

    int ans = -1;

    while (i < j) {
        mid = (i + j) / 2;

        if (j - i <= 3) {
            ans = CheckInSize3(arr, i, j);
            break;
        }

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            ans = arr[mid];
            break;
        } else if (arr[mid] == arr[mid + 1]) {
            i = mid + 2;
        } else {
            j = mid - 2;
        }
    }

    if (j - i <= 3) {
        ans = CheckInSize3(arr, i, j);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}
