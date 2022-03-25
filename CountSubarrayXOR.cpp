#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    int prefXOR = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        prefXOR = prefXOR ^ arr[i];

        if (prefXOR == k) {
            count++;
        }

        int y = prefXOR ^ k;
        if (freq.find(y) != freq.end()) {
            count += freq[y];
        }

        freq[prefXOR]++;
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