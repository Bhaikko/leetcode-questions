
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> merge(vector<vector<int>> intervals) {
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
    return answer;
}

void solution()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0];
        cin >> intervals[i][1];
    }

    vector<int> newinterval(2);
    cin >> newinterval[0] >> newinterval[1];

    vector<vector<int>> answer;
    for (int i = 0; i < n; i++) {
        if (intervals[i][0] > newinterval[0]) {
            answer.push_back(newinterval);
            newinterval[0] = INT_MAX;
        }

        answer.push_back(intervals[i]);
    }

    if (n == answer.size()) {
        answer.push_back(newinterval);
    }

    answer = merge(answer);
    
    cout << endl;
    for (auto a: answer) {
        for (auto b: a) {
            cout << b << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}