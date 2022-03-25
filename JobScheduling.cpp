#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int n;
    cin >> n;

    pp jobs[n];
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
        maxDeadline = max(maxDeadline, jobs[i].first);
    }

    set<int, greater<int>> availableSlots;
    for (int i = 1; i <= maxDeadline; i++) {
        availableSlots.insert(i);
    }

    sort(jobs, jobs + n, [](pp first, pp second) -> bool {
        return first.second > second.second;
    });

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int currentDeadline = jobs[i].first;

        set<int>::iterator lower = availableSlots.lower_bound(currentDeadline);
        if (lower != availableSlots.end()) {
            availableSlots.erase(lower);
            sum += jobs[i].second;
        }
    }

    cout << sum << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}