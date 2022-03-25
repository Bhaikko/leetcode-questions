#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution()
{
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX)), 
                        temp(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a][b] = w;
    }

    for (int k = 1; k <= n; k++) {
        temp = graph;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) {
                    continue;
                }

                int distance = graph[i][k] + graph[k][j];
                if (distance < temp[i][j]) {
                    temp[i][j] = distance;
                }
            }
        }
        graph = temp;
    }

    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << graph[src][dest] << endl;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}