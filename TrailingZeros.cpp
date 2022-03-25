#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n;
    cin >> n;

    int zeros = 0;
    
    while (n != 0) {
        zeros += (n / 5);
        n = n / 5;
    }
    
    cout << zeros << endl;;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solution();

    return 0;
}