#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool DifferByOne(string first, string second)
{
    if (first.size() != second.size()) {
        return false;
    }

    bool differed = false;
    for (int i = 0; i < first.size(); i++) {
        if (first[i] != second[i]) {
            if (differed) {
                return false;
            } else {
                differed = true;
            }
        }
    }

    return true;
}

int bfs(
    unordered_map<string, vector<string>>& graph,
    unordered_map<string, bool>& visited,
    string source,
    string destination
) {
    int count = 0;
    unordered_map<string, string> parents;

    queue<string> pending;
    pending.push(source);

    while (!pending.empty()) {
        string current = pending.front();
        pending.pop();

        // count++;
        if (current == destination) {
            string currparent = destination;
            // parents.erase(parents.find(source));
            while (true) {
                count++;
                currparent = parents[currparent];

                if (currparent == source) {
                    break;
                }

            }

            return count + 1;
        }

        for (string neighbor: graph[current]) {
            if (!visited[neighbor]) {
                parents[neighbor] = current;
                visited[neighbor] = true;
                pending.push(neighbor);
            }
        }
    }

    return 0;
}

void solution()
{
    int n;
    cin >> n;
    string beginWord, endWord;
    cin >> beginWord >> endWord;

    vector<string> wordList(n);
    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> visited;

    bool startFound = false;

    for (int i = 0; i < n; i++) {
        if (wordList[i] == beginWord) {
            startFound = true;
        }
        visited[wordList[i]] = false;
        for (int j = i + 1; j < n; j++) {
            if (DifferByOne(wordList[i], wordList[j])) {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }

    if (!startFound) {
        for (string word: wordList) {
            if (DifferByOne(word, beginWord)) {
                graph[beginWord].push_back(word);
                graph[word].push_back(beginWord);
            }
        }
    }

    // for (auto a: graph) {
    //     cout << a.first << ": ";
    //     for (string b: a.cout <<  << cond) {
    //         cout << b << " ";
    //     }

    //     cout << endl;
    // }

    cout << bfs(graph, visited, beginWord, endWord) << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}