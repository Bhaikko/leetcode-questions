#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n),
                prefix(n, 1),
                suffix(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] * prefix[i - 1];
    }

    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = arr[i] * suffix[i + 1];
    }

    arr[0] = suffix[1];
    arr[n - 1] = prefix[n - 2];
    for (int i = 1; i < n - 1; i++) {
        arr[i] = prefix[i - 1] * suffix[i + 1];
    }

    for (int a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}