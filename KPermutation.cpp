#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int fact[10];

void fillFact()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 9; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

unordered_map<int, bool> picked;

void kPermute(
    int n, 
    int k,
    int current, 
    string& ans
) {
    if (current == n + 1) {
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (picked.find(i) == picked.end()) {
            int ways = fact[n - current];

            if (k > ways) {
                k -= ways;
            } else {
                picked[i] = true;
                ans += to_string(i);
                kPermute(n, k, current + 1, ans);
                return;
            }
        }   
    }
}

void solution()
{
    fillFact();    

    int n, k;
    cin >> n >> k;

    string ans;
    kPermute(n, k, 1, ans);

    cout << ans << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}