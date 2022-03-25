#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int m, int n)
{
    if (n == 0) {
        return m;
    }

    return gcd(n, m % n);
}

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxEl = arr[0], 
        minEl = arr[0];

    for (int i = 0; i < n; i++) {
        maxEl = max(maxEl, arr[i]);
        minEl = min(minEl, arr[i]);
    }

    cout << gcd(maxEl, minEl) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}