#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> prevGreater(n),
                nextGreater(n);

    stack<int> pending;

    // Calculating next greater index
    for (int i = n - 1; i >= 0; i--) {
        if (pending.empty()) {
            nextGreater[i] = -1;
        } else {
            if (heights[pending.top()] > heights[i]) {
                nextGreater[i] = pending.top();
            } else {
                while (
                    !pending.empty() &&
                    heights[pending.top()] < heights[i]
                ) {
                    pending.pop();
                }
                nextGreater[i] = pending.empty() ? -1 : pending.top();
            }
        }

        pending.push(i);
    }

    // Calculating prevGreater index
    pending = stack<int>();
    for (int i = 0; i < n; i++) {
        if (pending.empty()) {
            prevGreater[i] = -1;
        } else {
            if (heights[pending.top()] > heights[i]) {
                prevGreater[i] = pending.top();
            } else {
                while (
                    !pending.empty() &&
                    heights[pending.top()] < heights[i]
                ) {
                    pending.pop();
                }
                prevGreater[i] = pending.empty() ? -1 : pending.top();
            }
        }

        pending.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        if (
            prevGreater[i] == -1 ||
            nextGreater[i] == -1
        ) {
            continue;
        }

        int width = nextGreater[i] - prevGreater[i] + 1;
        int height = min(
            heights[nextGreater[i]],
            heights[prevGreater[i]]
        );

        maxArea = max(maxArea, width * height);
    }

    cout << maxArea << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}