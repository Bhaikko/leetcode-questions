#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, k;
    cin >> n >> k;

    ll arr[n];

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    if (sum < k) {
        cout << -1 << endl;
        return;
    }

    sum = sum % k;
    cout << sum << endl;

    if (sum == 0) {
        cout << 0 << endl;
        return;
    }

    // Early check for specific element
    for (int i = 0; i < n; i++) {
        if (arr[i] == sum) {
            cout << 1 << endl;
            return;
        }
    }

    unordered_map<int, int> mp;
    mp[arr[0]] = 0;

    for (int i = 1; i < n; i++) {
        arr[i] = arr[i] + arr[i - 1];
        mp[arr[i]] = i;
    }

    ll len = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        if (arr[i] < sum) {
            continue;
        } else {
            ll x = arr[i] - sum;
            if (x == 0) {
                len = min(len, i);
            }

            if (mp.find(x) == mp.end()) {
                continue;
            } else {
                cout << len << endl;
                len = min(len, i - mp[x]);
            }
        }
    }

    if (len == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << len << endl;

    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}