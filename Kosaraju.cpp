#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void topological(
    vector<int> graph[],
    int n,
    int currentVertex,
    vector<bool>& visited,
    stack<int>& topoSort
) {
    if (visited[currentVertex]) {
        return;
    }

    visited[currentVertex] = true;

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int neighbor = graph[currentVertex][i];

        if (!visited[neighbor]) {
            topological(graph, n, neighbor, visited, topoSort);
        }
    }

    topoSort.push(currentVertex);
}

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    // Getting Topological sort for finishing times
    stack<int> topoSort;
    vector<bool> visited(n, false); 

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topological(graph, n, i, visited, topoSort); 
        }
    }

    // Transposing graph
    vector<int> transposed[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            transposed[graph[i][j]].push_back(i);
        }
    }

    // Dfs on transposed to get SCC
    visited = vector<bool>(n, false);

    int sccCount = 0;
    stack<int> temp;

    while (!topoSort.empty()) {
        int i = topoSort.top();
        topoSort.pop();

        if (!visited[i]) {            
            sccCount++;
            topological(transposed, n, i, visited, temp);
        }
    }

    cout << endl << sccCount << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}