#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string word;
    cin >> word;

    int zerosOnRight = 0,
        onesOnLeft = 0;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == '0') {
            zerosOnRight++;
        } 
    }

    int answer = INT_MAX;

    for (int i = 0; i < word.size(); i++) {
        answer = min(answer, zerosOnRight + onesOnLeft);

        if (word[i] == '0') {
            zerosOnRight--;
        } else {
            onesOnLeft++;
        }
    }

    answer = min(answer, zerosOnRight + onesOnLeft);

    cout << answer << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

// 101010111001010000011101101110