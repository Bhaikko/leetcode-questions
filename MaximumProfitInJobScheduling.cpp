#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Job 
{
    int start;
    int end;
    int profit;  
};

void jobScheduling(
    vector<Job>& jobs,
    int index,
    int& maxProfit,
    int currentProfit,
    int currentTime
) {
    if (index == jobs.size()) {
        return;
    }

    for (int i = index; i < jobs.size(); i++) {
        if (jobs[i].start >= currentTime) {
            maxProfit = max(maxProfit, currentProfit + jobs[i].profit);
            jobScheduling(jobs, i + 1, maxProfit, currentProfit + jobs[i].profit, jobs[i].end);
        }
    }
}

void solution()
{
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].start;
    }

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].end;
    }

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), [](Job first, Job second) -> bool {
        return first.start < second.start;
    });

    int maxProfit = 0;
    jobScheduling(jobs, 0, maxProfit, 0, 0);

    cout << maxProfit << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << jobs[i].start << " " << jobs[i].end << " " << jobs[i].profit << endl;
    // }

    vector<int> profits(n, 0);
    // profits[n - 1] = jobs[n - 1].profit;
    for (int i = 0; i < n; i++) {
        profits[i] = jobs[i].profit;
    }
    int answer = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int k = i + 1; k <= n - 1; k++) {
            if (jobs[i].end <= jobs[k].start) {
                profits[i] = max(
                    profits[i],
                    jobs[i].profit + profits[k]
                );
            }
        }
        answer = max(answer, profits[i]);
    }
    cout << answer << endl;

    // for (int a: profits) {
    //     cout << a << " ";
    // }
    // cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}