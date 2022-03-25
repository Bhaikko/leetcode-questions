#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());

    int l = 1,
        r = stalls[stalls.size() - 1] - stalls[0];
    int maxDistance = 0;

    while (l <= r) {
        int distance = (l + r) / 2;

        int cowsAssigned = 1;
        int currentStall = 0;
        for (int i = 1; i < n; i++) {
            if (stalls[i] - stalls[currentStall] >= distance) {
                cowsAssigned++;
                currentStall = i;
            }
        }

        if (cowsAssigned >= k) {
            maxDistance = max(distance, maxDistance);
            l = distance + 1;
        } else {
            r = distance - 1;
        }
    }

    cout << maxDistance << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}