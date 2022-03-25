#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double power(double x, int n)
{
    if (n == 1) {
        return x;
    }

    double value = power(x, floor(n / 2));
    value *= value;
    
    if ((n & 1) == 1) {
        value *= x;
    }

    return value;

}

void solution()
{
    double x;
    int n;

    cin >> x >> n;

    if (n < 0) {
        cout << 1.0f / power(x, abs(n)) << endl;
    } else {
        cout << power(x, n) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}