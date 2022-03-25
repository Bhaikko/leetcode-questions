#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string s;
    getline(cin, s);

    string ans = "";

    int start = 0,
        end = 0,
        n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            ans = s.substr(start, end - start + 1) + ' ' + ans;
            
            while (s[i] == ' ') {
                i++;
            }

            start = i;
            i--;
        } else {
            end = i;
        }
    }

    ans = s.substr(start, end - start + 1) + ' ' + ans;
    
    int i = n - 1;
    while (ans[i] == ' ') {
        ans.pop_back();
        i--;
    }

    if (ans[0] == ' ') {
        ans = ans.substr(1);
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