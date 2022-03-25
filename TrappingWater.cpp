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

    int l = 0,
        r = n - 1,
        leftMax = 0,
        rightMax = 0,
        water = 0;

    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] >= leftMax) {
                leftMax = arr[l];
            } else {
                water += leftMax - arr[l];
            }
            l++;
        } else {
            if (arr[r] >= rightMax) {
                rightMax = arr[r];
            } else {
                water += rightMax - arr[r];
            }
            r--;
        }
    }

    cout << water << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}