#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, nums[i]);
    }

    int minProd = 1,
        maxProd = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            minProd = 1;
            maxProd = 1;
            continue;
        } 
        
        int a = minProd * nums[i];
        int b = maxProd * nums[i];

        maxProd = max(max(minProd, maxProd), nums[i]);
        minProd = min(min(minProd, maxProd), nums[i]);
    

        ans = max(ans, maxProd);
    }

    // ans = max(ans, max(minProd, maxProd));
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);

    solution();

    return 0;
}