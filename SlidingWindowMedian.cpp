#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<double> right_;
    multiset<double, greater<double>> left_;

void balance()
{
    if((int)right_.size() - (int)left_.size() > 1)
    {
        left_.insert(*right_.begin());
        right_.erase(right_.begin());
    }
    else if((int)left_.size() - (int)right_.size() > 1)
    {
        right_.insert(*left_.begin());
        left_.erase(left_.begin());
    }
}

void push(int num)
{
    if (!right_.empty() && num >= *right_.begin()) {
        right_.insert(num);
    } else {
        left_.insert(num);
    }

    balance();
}

double getMedian()
{
    if (left_.size() == right_.size()) {
        return (*left_.begin() + *right_.begin()) / 2.0f;
    } else {
        if (left_.size() > right_.size()) {
            return *left_.begin();
        }

        return *right_.begin();
    }
}

void remove(int el)
{
    auto it = left_.find(el);
    if (it != left_.end()) {
        left_.erase(it);
    } else {
        it = right_.find(el);
        right_.erase(it);
    }
    
    balance();
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < k; i++) {
        push(nums[i]);
    }
    vector<double> answer;
    answer.push_back(getMedian());

    for (int i = k; i < n; i++) {
        remove(nums[i - k]);
        push(nums[i]);
        answer.push_back(getMedian());
    }

    return answer;
}

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<double> ans = medianSlidingWindow(nums, k);

    for (double a: ans) {
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