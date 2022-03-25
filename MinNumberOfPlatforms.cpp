#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int start[n], end[n];

    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }

    sort(start, start + n);
    sort(end, end + n);

    int currentEndIndex = 0;

    int count = 0,
        maxCount = 0;

    for (int i = 0; i < n;) {
        if (start[i] <= end[currentEndIndex]) {
            count++;
            maxCount = max(maxCount, count);

            i++;
        } else {
            currentEndIndex++;
            count--;
        }
    }

    cout << maxCount << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}