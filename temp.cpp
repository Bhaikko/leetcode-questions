#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    map<int, int> left;
    left[2] = 1;
    left[1] = 1;
    left[1] = 1;
    left[4] = 1;
    left[5] = 1;
    left[3] = 1;

    cout << (*left.begin()).first << endl;
    cout << (*left.upper_bound(2)).first << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}