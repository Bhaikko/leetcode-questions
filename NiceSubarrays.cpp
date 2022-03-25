#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int subarraySum(vector<int>& arr, int k) {
    int n = arr.size();


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

    // cout << count << endl;
    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = (nums[i] & 1) ? 1 : 0;
    }
    
    return subarraySum(nums, k);
}

void solution()
{
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}