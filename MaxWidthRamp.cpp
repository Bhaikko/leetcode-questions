#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int n;
    cin >> n;

    pp arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + n, [](pp first, pp second) -> bool {
        return first.first < second.first;
    });

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    int minTillNow = arr[0].second;
    int maxDif = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i].second < minTillNow) {
            minTillNow = arr[i].second;
        }

        maxDif = max(arr[i].second - minTillNow, maxDif);
    }

    cout << maxDif << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}