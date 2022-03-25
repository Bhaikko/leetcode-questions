#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkEquality(vector<string>& strs, int idx)
{
    for (int i = 0; i < strs.size() - 1; i++) {
        if (strs[i][idx] != strs[i + 1][idx]) {
            return false;
        }
    }

    return true;
}

void solution()
{
    int n;
    cin >> n;

    int minLen = INT_MAX;
    vector<string> strs(n);
    
    for (int i = 0; i < n; i++) {
        cin >> strs[i];

        minLen = min(minLen, (int)strs[i].size());
    }

    int k = 0;

    while (k < minLen) {
        if (checkEquality(strs, k)) {
            k++;
        } else {
            break;
        }
    }

    cout << strs[0].substr(0, k) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}