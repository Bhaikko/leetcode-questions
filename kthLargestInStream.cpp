#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pending;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        if (nums.size() == 0) {
            return;
        }
        
        for (int i = 0; i < k; i++) {
            if (i >= nums.size()) {
                break;
            }
            pending.push(nums[i]);
        }
        
        for (int i = k; i < nums.size(); i++) {
            if (pending.top() < nums[i]) {
                pending.pop();
                pending.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if (pending.size() < k) {
            pending.push(val);
            return pending.top();
        }
        
        if (pending.top() < val) {
            pending.push(val);
            pending.pop();
        }
        
        return pending.top();
    }
};

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