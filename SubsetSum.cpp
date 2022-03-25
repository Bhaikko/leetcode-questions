#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void subsetSum(
    vector<int> arr, 
    int current, 
    int n, 
    int prevSum,
    vector<int>& sums
) {
    sums.push_back(prevSum);
    if (current == n) {
        return;
    }

    for (int i = current; i < n; i++) {
        prevSum += arr[i];
        subsetSum(arr, i + 1, n, prevSum, sums);
        prevSum -= arr[i];
    }
}

void solution()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sums;
    
    subsetSum(arr, 0, arr.size(), 0, sums);
    sort(sums.begin(), sums.end());
    for (int a: sums) {
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