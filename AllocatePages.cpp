#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    int sum = 0,
        minEl = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
        minEl = min(minEl, arr[i]);
    }

    int l = minEl,  
        r = sum;

    int minPages = sum;

    while (l <= r) {
        int pageToAllocate = (l + r) / 2;
        
        int currSum = 0;
        int childrenAssigned = 1;
        
        for (int i = 0; i < n; i++) {
            if (currSum + arr[i] > pageToAllocate) {
                childrenAssigned++;
                currSum = 0;
                if (arr[i] > pageToAllocate) {
                    childrenAssigned = m + 1;
                    break;
                } 
            }

            currSum += arr[i];
        }
        
        if (childrenAssigned <= m) {
            minPages = min(minPages, pageToAllocate);
            r = pageToAllocate - 1;
        } else {
            l = pageToAllocate + 1;
        }
    }

    cout << minPages << endl;
    // return minPages;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
    
    return 0;
}