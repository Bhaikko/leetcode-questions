#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int arr[n];
    unordered_map<int, int> prefix;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxLen = 0;
    int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;
        } else {
            if (prefix.find(prefixSum) == prefix.end()) {
                prefix[prefixSum] = i;
            } else {
                maxLen = max(maxLen, i - prefix[prefixSum]);
            }
        }
    }

    cout << maxLen << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}