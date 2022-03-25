#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> smaller;
    smaller.push(INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
        if (!smaller.empty() && smaller.top() < arr[i]) {
            ans[i] = smaller.top();
        } else {
            while (!smaller.empty() && smaller.top() >= arr[i]) {
                smaller.pop();
            }
            ans[i] = smaller.empty() ? -1 : smaller.top();
        }

        smaller.push(arr[i]);
    }

    for (int a: ans) {
        cout << a << " ";
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