#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string input;
    cin >> input;

    unordered_map<char, int> freq_map;
    int maxCount = 0;
    int count = 0;

    int l = 0,
        r = 0;

    while (r < input.size()) {
        if (freq_map.find(input[r]) == freq_map.end()) {
            freq_map[input[r]] = r;
        } else {
            if (freq_map[input[r]] >= l) {
                l = freq_map[input[r]] + 1;
            } 
            freq_map[input[r]] = r;
        }

        maxCount = max(maxCount, r - l + 1);
        r++;
    }

    maxCount = max(maxCount, r - l);

    cout << maxCount << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}