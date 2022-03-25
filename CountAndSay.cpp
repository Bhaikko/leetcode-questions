#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string sayPart(string input)
{
    int count = 1;
    int n = input.size();
    string output = "";

    for (int i = 0; i < n - 1; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output += to_string(count) + input[i];
            count = 1;
        }
    }

    output += to_string(count) + input[n - 1];

    return output;
}

string countAndSay(int n)
{
    string out = "1";

    for (int i = 2; i <= n; i++) {
        out = sayPart(out);
    }

    return out;
}

void solution()
{
    int n;
    cin >> n;

    cout << countAndSay(n) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}