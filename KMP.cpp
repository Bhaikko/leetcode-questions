#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void fillLps(string& p, vector<int>& lps)
{
    lps[0] = 0;

    int j = 0;

    for (int i = 1; i < p.size(); i++) {
        if (p[i] == p[j]) {
            lps[i] = ++j;
        } else {
            while (j != 0) {
                j = lps[j - 1];
                if (p[j] == p[i]) {
                    lps[i] = ++j;
                    break;
                }
            }
        }
    }

}

void solution()
{
    string s, p;
    cin >> s >> p;

    vector<int> lps(p.size());

    fillLps(p, lps);

    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == p[j]) {
            j++;
        } else {
            while (j != 0) {
                j = lps[j - 1];
                if (s[i] == p[j]) {
                    j++;
                    break;
                }
            }
        }

        if (j == p.size()) {
            cout << "Matched" << endl;
            return;
        }
    }

    cout << "Didnt Matched" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}