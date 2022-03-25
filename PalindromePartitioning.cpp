#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

void partition(
    string s, 
    vector<vector<string>>& answers,
    vector<string> palindromes
) {
    if (s.size() == 0) {
        answers.push_back(palindromes);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (isPalindrome(s.substr(0, i + 1))) {
            palindromes.push_back(s.substr(0, i + 1));
            partition(s.substr(i + 1), answers, palindromes);
            palindromes.pop_back();
        }
    }
}

void solution()
{
    string s;
    cin >> s;

    vector<vector<string>> answers;
    vector<string> palin;

    partition(s, answers, palin);

    for (vector<string> a: answers) {
        for (string b: a) {
            cout << b << " ";
        }

        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}