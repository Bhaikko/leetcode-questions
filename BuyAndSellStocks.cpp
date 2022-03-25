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

    int maxFromRight = -1;
    int maxProfit = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        maxFromRight = max(maxFromRight, arr[i]);
        maxProfit = max(maxProfit, maxFromRight - arr[i]);
    }

    cout << maxProfit << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}