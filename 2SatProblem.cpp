#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void TryDFS(
    vector<int> graph[], 
    int currentVertex, 
    bool& hasFound, 
    bool isVisited[],
    int end
) {
    if (currentVertex == end) {
        hasFound = true;
        return;
    }
    
    isVisited[currentVertex] = true;

    if (hasFound) {
        return;
    }

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int neigbor = graph[currentVertex][i];
        if (!isVisited[neigbor]) {
            TryDFS(graph, neigbor, hasFound, isVisited, end);
        }
    }
}

void FillIds(unordered_map<string, int>& ids, string preposition, int& currentId)
{
    if (ids.find(preposition) == ids.end()) {
        ids[preposition] = currentId++;
        ids["~" + preposition] = currentId++;
    }
}

int GetId(unordered_map<string, int>& ids, string preposition) {
    return ids[preposition];
}

void solution()
{
    int n;
    cin >> n;

    string equations[n];
    for (int i = 0; i < n; i++) {
        cin >> equations[i];
    }

    unordered_map<string, int> ids;
    int currentId = 1;

    set<string> letters;
    for (int i = 0; i < n; i++) {
        FillIds(ids, equations[i].substr(0, 1), currentId);
        FillIds(ids, equations[i].substr(3, 1), currentId);

        letters.insert(equations[i].substr(0, 1));
        letters.insert(equations[i].substr(3, 1));
    }

    // Creating Graph
    vector<int> graph[currentId];
    for (int i = 0; i < n; i++) {
        string first = equations[i].substr(0, 1);
        string second = equations[i].substr(3, 1);

        if (equations[i].substr(1, 1) == "!") {
            graph[GetId(ids, "~" + first)].push_back(GetId(ids, second));
            graph[GetId(ids, "~" + second)].push_back(GetId(ids, first));

            graph[GetId(ids, first)].push_back(GetId(ids, "~" + second));
            graph[GetId(ids, second)].push_back(GetId(ids, "~" + first));
        } else {
            graph[GetId(ids, "~" + first)].push_back(GetId(ids, "~" + second));
            graph[GetId(ids, second)].push_back(GetId(ids, first));

            graph[GetId(ids, "~" + second)].push_back(GetId(ids, "~" + first));
            graph[GetId(ids, first)].push_back(GetId(ids, second));
        }
    }

    bool answer = false;
    bool isVisited[currentId];

    for (auto i = letters.begin(); i != letters.end(); i++) {
        for (int i = 1; i <= currentId; i++) {
            isVisited[i] = false;
        }

        TryDFS(graph, GetId(ids, *i), answer, isVisited, GetId(ids, "~" + *i));

        if (answer) {
            break;
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


/*
    3
    a==b
    b!=c
    c==a
*/




















