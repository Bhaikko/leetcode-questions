#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Time 
{
    int id;
    int start;
    int end;
};

void solution()
{
    int n;
    cin >> n;

    Time times[n];

    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i];
        times[i].id = i + 1;
        times[i].start = start[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> end[i];
        times[i].end = end[i];
    }

    sort(times, times + n, [](Time time1, Time time2) -> bool {
        if (time1.end == time2.end) {
            return time1.id < time2.id;
        }

        return time1.end < time2.end;
    });

    vector<int> answer;
    int lastEndTime = -1;
    for (int i = 0; i < n; i++) {
        if (times[i].start > lastEndTime) {
            answer.push_back(times[i].id);
            lastEndTime = times[i].end;
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
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