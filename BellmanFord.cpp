#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int dest;
    int weight;
};

void solution()
{
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;

    vector<Edge> graph[n + 1];
    vector<ll> distances(n + 1, INT_MAX);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        Edge edge;
        edge.dest = b;
        edge.weight = w;

        graph[a].push_back(edge);
    }

    distances[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int v = 1; v <= n; v++) {
            for (int e = 0; e < graph[v].size(); e++) {
                ll distance = distances[v] + graph[v][e].weight;

                if (distance < distances[graph[v][e].dest]) {
                    distances[graph[v][e].dest] = distance;
                }
            }
        }
    }

    // Checking for -ve cycle
    for (int v = 1; v <= n; v++) {
        for (int e = 0; e < graph[v].size(); e++) {
            ll distance = distances[v] + graph[v][e].weight;

            if (distance < distances[graph[v][e].dest]) {
                cout << "NEGATIVE CYCLE" << endl;
                // distances[graph[v][e].dest] = distance;
                return;
            }
        }
    }

    cout << distances[dest] << endl;
    // for (int a: distances) {
    //     cout << a << " ";
    // }

    // cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solution();

    return 0;
}