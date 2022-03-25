#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cycle(
    vector<vector<int>>& graph,
    int n,
    int current,
    vector<bool>& visited,
    vector<bool>& dfsVisited
) {
    visited[current] = true;
    dfsVisited[current] = true;

    for (int i = 0; i < graph[current].size(); i++) {
        int neighbor = graph[current][i];

        if (!visited[neighbor]) {
            if (cycle(graph, n, neighbor, visited, dfsVisited)) {
                return true;
            }
        } else if (dfsVisited[neighbor]) {
            return true;
        }
    }

    dfsVisited[current] = false;
    return false;

}

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> prerequisites(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        prerequisites[a].push_back(b);
    }

    vector<bool> visited(n, false), dfsVisited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (cycle(prerequisites, n, i, visited, dfsVisited)) {
                cout << "false" << endl;
                return;
            }
        }
    }
    cout << "true" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}