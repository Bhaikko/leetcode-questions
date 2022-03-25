#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<string, int> fillMap()
{
    unordered_map<string, int> r;
    r["I"] = 1;
    r["V"] = 5;
    r["X"] = 10;
    r["L"] = 50;
    r["C"] = 100;
    r["D"] = 500;
    r["M"] = 1000;
    r["IV"] = 4;
    r["IX"] = 9;
    r["XL"] = 40;
    r["XC"] = 90;
    r["CD"] = 400;
    r["CM"] = 900;

    return r;
}

void solution()
{
    string s;
    cin >> s;

    int n = s.size();

    unordered_map<string, int> r = fillMap();

    int l = 1,
        ans = 0;
    for (int i = 0; i < n; i++) {
        if (l != n) {
            if (r.find(s.substr(i, 2)) != r.end()) {
                ans += r[s.substr(i, 2)];
                i++;
            } else {
                ans += r[s.substr(i, 1)];
            }   
        } else {
            ans += r[s.substr(i, 1)];
        }
        
        l++;
    }

    cout << ans << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}