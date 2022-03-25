#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void TopologicalSort(
    vector<int> graph[], 
    int n, 
    int current, 
    vector<bool>& visited,
    stack<int>& sort 
) {
    if (visited[current]) {
        return;
    }

    visited[current] = true;

    for (int i = 0; i < graph[current].size(); i++) {
        int neighbor = graph[current][i];

        if (!visited[neighbor]) {
            TopologicalSort(graph, n, neighbor, visited, sort);
        }
    }
    sort.push(current);
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

    stack<int> sort;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            TopologicalSort(graph, n, i, visited, sort);
        }
    }

    while (!sort.empty()) {
        cout << sort.top() << " ";
        sort.pop();
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