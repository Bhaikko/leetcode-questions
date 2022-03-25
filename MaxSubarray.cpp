#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0,
        maxSumTillNow = arr[0];

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        maxSumTillNow = sum > maxSumTillNow ? sum : maxSumTillNow;
        sum = sum < 0 ? 0 : sum;
    }

    cout << maxSumTillNow << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}