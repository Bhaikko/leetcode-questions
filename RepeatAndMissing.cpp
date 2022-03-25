#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int dupe = -1;
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i])] >= 0) {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        } else {
            dupe = arr[i];
        }
    }

    cout << dupe << endl;

    int actualSum = n * (n + 1) / 2;

    cout << sum << " " << actualSum << endl;

    int ans = dupe - sum + actualSum;

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}