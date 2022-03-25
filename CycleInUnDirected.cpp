#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cycle(
    vector<int> graph[], 
    int n, 
    int currentVertex, 
    vector<bool>& visited,
    int parent
) {
    visited[currentVertex] = true;

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int currentNeighbor = graph[currentVertex][i];

        if (!visited[currentNeighbor]) {
            if (cycle(graph, n, currentNeighbor, visited, currentVertex)) {
                return true;
            } 
        } else if (currentNeighbor != parent) {
            return true;
        }
    }

    return false;
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
        graph[b].push_back(a);
    }

    vector<bool> visited(n, 0);

    cout << (cycle(graph, n, 0, visited, -1) == 1? "True" : "False") << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}