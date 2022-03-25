#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

void solution()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        vector<int> interval;
        interval.push_back(a);
        interval.push_back(b);

        intervals.push_back(interval);
    }   

    sort(intervals.begin(), intervals.end(), [](vector<int> first, vector<int> second) -> bool {
        if (first[0] == second[0]) {
            return first[1] < second[1];
        }

        return first[0] < second[0];

    });

    vector<vector<int>> answer;

    vector<int> currentInterval;
    currentInterval.push_back(intervals[0][0]);
    currentInterval.push_back(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++) {
        if (currentInterval[1] >= intervals[i][0]) {
            currentInterval[1] = max(intervals[i][1], currentInterval[1]);
        } else {
            answer.push_back(currentInterval);
            currentInterval.clear();
            currentInterval.push_back(intervals[i][0]);
            currentInterval.push_back(intervals[i][1]);
        }
    }

    answer.push_back(currentInterval);
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i][0] << " " << answer[i][1] << endl;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}