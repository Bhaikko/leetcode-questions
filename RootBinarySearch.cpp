#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

float nthPower(int x, float lower, float upper, int n)
{
    float mid = (upper + lower) / 2;

    float midPow = powf(mid, n);
    float diff = fabs(midPow - x);

    // cout << mid << " " << midPow << " " << diff << endl;

    if (diff <= 0.01f) {
        return mid;
    }

    if (x < midPow) {
        return nthPower(x, lower, mid - 1, n);
    } else {
        return nthPower(x, mid + 1, upper, n);
    }
}

void solution()
{
    int x, n;
    cin >> x >> n;

    int upper = 1;

    while (pow(upper, n) < x) {
        upper++;
    }

    if (pow(upper, n) == x) {
        cout << upper << endl;
        return; 
    }

    int lower = upper - 1;

    // cout << (int)nthPower(x, lower, upper, n) << endl;
    cout << nthPower(x, lower, upper, n) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}