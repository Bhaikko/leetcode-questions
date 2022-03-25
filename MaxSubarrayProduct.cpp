#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    int maxEl = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        maxEl = max(maxEl, arr[i]);
    }    

    int ans = maxEl;

    int maxTillNow = arr[0];
    int maxTillNowNeg = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > 0) {
            if (maxTillNow < 0) {
                maxTillNow = arr[i];
                maxTillNowNeg *= arr[i];
            } else if (maxTillNow == 0) {
                maxTillNow = arr[i];
                maxTillNowNeg = arr[i];
            } else {
                maxTillNow *= arr[i];
                maxTillNowNeg *= arr[i];
            }
        } else if (arr[i] == 0) {
            ans = max(max(maxTillNow, maxTillNowNeg), ans);
            maxTillNow = 0;
            maxTillNowNeg = 0;
        } else {
            maxTillNowNeg *= arr[i];

            ans = max(max(maxTillNow, maxTillNowNeg), ans);

            if (maxTillNowNeg > 0) {
                maxTillNow = maxTillNowNeg;
                maxTillNowNeg = arr[i];

            } else {
                maxTillNow = arr[i];
            }
        }
    }

    ans = max(max(maxTillNow, maxTillNowNeg), ans);

    cout << ans << endl;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}