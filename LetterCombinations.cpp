#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string GetNumPad(int key)
{
    switch (key) {
        case 2:
            return "abc";
            break;
        case 3:
            return "def";
            break;
        case 4:
            return "ghi";
            break;
        case 5:
            return "jkl";
            break;
        case 6:
            return "mno";
            break;
        case 7:
            return "pqrs";
            break;
        case 8:
            return "tuv";
            break;
        case 9:
            return "wxyz";
            break;
        default: 
            break;
    }

    return "fff";
}

void LetterCombinations(
    string& word,
    int currentIndex,
    vector<string>& lastWords
) {
    if (currentIndex >= word.size()) {
        return;
    }

    string currentKey = GetNumPad(stoi(word.substr(currentIndex, 1)));

    vector<string> newWords;
    for (int i = 0; i < lastWords.size(); i++) {
        for (int j = 0; j < currentKey.size(); j++) {
            string newWord = lastWords[i] + currentKey[j];

            newWords.push_back(newWord);
        }
    }

    lastWords = newWords;

    LetterCombinations(word, currentIndex + 1, lastWords);

}

void solution()
{
    string digits;
    cin >> digits;

    vector<string> answer;
    answer.push_back("");

    LetterCombinations(digits, 0, answer);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}