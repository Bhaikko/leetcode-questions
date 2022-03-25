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

    stack<int> larger;
    larger.push(INT_MIN);

    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n;
        if (!larger.empty() && arr[index] < larger.top()) {
            ans[index] = larger.top();
        } else {
            while (!larger.empty() && larger.top() <= arr[index]) {
                larger.pop();
            }
            ans[index] = (larger.empty()) ? -1 : larger.top();
        }

        larger.push(arr[index]);
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