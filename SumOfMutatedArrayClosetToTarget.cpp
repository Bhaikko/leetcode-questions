#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, target;
    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int end = INT_MIN,
        start = INT_MAX;
    
    
    for (int i = 0; i < n; i++) {
        end = max(end, arr[i]);
    }

    start = 0;            
    
    int answer = INT_MAX;
    int minAbsoluteDifference = INT_MAX;
    
    while (start <= end) {
        int mid = (start + end) / 2;

        int tempArr[n];
        
        for (int i = 0; i < n; i++) {
            tempArr[i] = arr[i];
        }
        
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            tempArr[i] = tempArr[i] > mid ? mid : tempArr[i];
            
            sum += tempArr[i];
        }
        
        int currentSumDifference = abs(sum - target);

        if (currentSumDifference <= minAbsoluteDifference) {
            cout << mid << endl;
            if (currentSumDifference == minAbsoluteDifference) {
                answer = min(answer, mid);
            } else {
                answer = mid;    
            }

            minAbsoluteDifference = currentSumDifference;
        }

        if (sum >= target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }            
    }

    cout << answer << endl;
        
        // return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}