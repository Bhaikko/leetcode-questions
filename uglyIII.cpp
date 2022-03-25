#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll GetLCM(ll a, ll b) {
    ll lcm;

    if (a > b) {
        lcm = a;
    } else {
        lcm = b;
    }

    while (true) {
        if (lcm % a == 0 && lcm % b == 0) {
            return lcm;
        }
        lcm++;
    }

    return 0;
}

int solution()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll lcm = GetLCM(a, GetLCM(b, c));
        
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}