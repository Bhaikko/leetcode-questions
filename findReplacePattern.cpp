#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string Compress(string word) {
    string answer = "";

    int count = 0;
    string letter = word.substr(0, 1);
    for (int i = 0; i < word.length(); i++) {
        if (letter == word.substr(i, 1)) {
            count++;
        } else {
            answer += letter + to_string(count);

            letter = word.substr(i, 1);
            count = 1;
        }
    }

    answer += letter + to_string(count);
    return answer;
}

bool CheckPattern(string word, string pattern) {
    unordered_map<string, string> mapping;
    unordered_map<string, bool> mapper;

    for (int i = 0; i < pattern.size(); i++) {
        mapper[pattern.substr(i, 1)] = false;
    }

    int i = 1;

    while (true) {
        string letterWord = word.substr(i - 1, 1);
        string letterPattern = pattern.substr(i - 1, 1);

        // cout << letterWord << " " << letterPattern << endl;

        if (mapping.find(letterWord) == mapping.end()) {
            if (mapper[letterPattern]) {
                return false;
            }
            mapping[letterWord] = letterPattern;
            mapper[letterPattern] = true;
        } else {
            if (letterPattern != mapping[letterWord]) {
                return false;
            }
        }

        if (word[i] != pattern[i]) {
            return false;
        }

        i += 2;

        if (i >= word.length()) {
            break;
        }
    }

    return true;
}

void solution()
{
    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    string words[n];
    string compressedWords[n];
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        compressedWords[i] = Compress(words[i]);

        // cout << compressedWords[i] << " ";
    }  

    string compressedPattern = Compress(pattern);

    vector<string> answer;

    for (int i = 0; i < n; i++) {
        if (compressedWords[i].length() == compressedPattern.length()) {
            if (CheckPattern(compressedWords[i], compressedPattern)) {
                answer.push_back(words[i]);
            }
        } 
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}

/*
6 abb
abc deq mee aqq dkd ccc

5 abc
abc cba xyx yxx yyx

5 baba
badc abab dddd dede yyxx

*/