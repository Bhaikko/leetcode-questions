#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    string word;
    cin >> word;
    
    stack<int> indexes;
    indexes.push(-1);

    int answer = 0;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == '(') {
            indexes.push(i);
        } else {
            indexes.pop();

            if (indexes.empty()) {
                indexes.push(i);
            } else {
                answer = max(answer, i - indexes.top());
            }
        }
    }

    cout << answer << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}