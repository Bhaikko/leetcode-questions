#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int prefixSum = 0,
        count = 0;
    unordered_map<int, int> sumCounts;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == k) {
            count++;
        } 

        int x = prefixSum - k;

        if (sumCounts.find(x) != sumCounts.end()) {
            count += sumCounts[x];
        }

        sumCounts[prefixSum]++;
    }

    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}