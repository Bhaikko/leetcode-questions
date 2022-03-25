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

    int slow = arr[arr[0]], fast = arr[slow];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

    fast = arr[0];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    cout << slow << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}