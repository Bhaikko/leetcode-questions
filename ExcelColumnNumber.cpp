#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string in;
    cin >> in;

    int col = 0;
    int k = 0;

    // 65 - A
    for (int i = in.size() - 1; i >= 0; i--) {
        int curr = (int)(in[i]) - 65 + 1;

        col = col + curr * pow(26, k++);
    }

    cout << col << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}
