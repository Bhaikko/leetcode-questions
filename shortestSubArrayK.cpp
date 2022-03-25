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

    
    ll prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    int ans = n + 1;
    deque<int> monoq;

    for (int y = 0; y < n + 1; y++) {
        while (!monoq.empty() && prefixSum[y] <= prefixSum[monoq.back()]) {
            monoq.pop_back();
        }

        while (!monoq.empty() && prefixSum[y] >= prefixSum[monoq.front()] + k) {
            ans = min(ans, y - monoq.front());
            monoq.pop_front();
        }

        monoq.push_back(y);
    }

    cout << (ans < n + 1 ? ans : -1) << endl; 

    // for (int y = 0; y <= n; y++) {
    //     for (int x = y - 1; x >= 0; x--) {
    //         if (prefixSum[y] - prefixSum[x] >= k) {
    //             if (y - x < minLength) {
    //                 minLength = y - x;
    //             }
    //         }
    //     }
    // }




}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

// GFG Solution
/*
    int minLength = n + 1;
    int startIndex = 0;
    int endIndex = 0;
    int currentSum = 0;
    bool moveStart = true;

    while (true) {
        
        if (startIndex >= n || endIndex >= n) {
            break;
        }
        // cout << startIndex << " " << endIndex << endl;

        if (moveStart) {
            currentSum += arr[startIndex];
            if (currentSum >= k) {
                minLength = startIndex - endIndex + 1;
                moveStart = false;
            }
            startIndex++;
        } else {
            currentSum -= arr[endIndex];
            if (currentSum >= k) {
                minLength = startIndex - endIndex + 1;
                moveStart = true;
            }
            endIndex++;
        }
        if (startIndex == endIndex) {
            break;
        }
    }   

    if (minLength <= n) {
        cout << minLength << endl;
    } else {
        cout << -1 << endl;
    }
*/

// Leetcode Solution
