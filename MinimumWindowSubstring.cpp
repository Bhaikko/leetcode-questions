#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> windowFreq, tFreq;
    for (int i = 0; i < t.size(); i++) {
        tFreq[t[i]]++;
        windowFreq[t[i]] = 0;
    }

    int l = 0,
        r = 0,
        have = 0,
        need = t.size(),
        minLen = INT_MAX,
        index = -1,
        n = s.size();

    // Setting L position
    while (l < n) {
        if (tFreq.find(s[l]) == tFreq.end()) {
            l++;
        } else {
            break;
        }
    }

    r = l;

    while (r < n) {
        
        if (windowFreq.find(s[r]) != windowFreq.end()) {
            windowFreq[s[r]]++;

            cout << s[r] << " " << windowFreq[s[r]] << " " << tFreq[s[r]] << endl;
            if (windowFreq[s[r]] <= tFreq[s[r]]) {
                have++;
            }
        }

        // cout << l << " " << r << " " << have << " " << need << endl;
        while (have == need) {
            int len = r - l + 1;
            if (len < minLen) {
                minLen = len;
                index = l;
            }

            if (windowFreq.find(s[l]) != windowFreq.end()) {
                windowFreq[s[l]]--;

                if (windowFreq[s[l]] < tFreq[s[l]]) {
                    have--;
                }
            }
            l++;
        }

        r++;
    }

    cout << minLen << endl;

    if (index == -1) {
        cout << "" << endl;
    } else {
        cout << s.substr(index, minLen) << endl;
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}