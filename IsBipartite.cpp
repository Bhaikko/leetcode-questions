#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isBiPartite(
    vector<vector<int>>& graph,
    int n,
    int source,
    vector<int>& colors
) {
    queue<int> pending;

    pending.push(source);

    while (!pending.empty()) {
        int current = pending.front();
        pending.pop();
        bool red = true, blue = true;

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];

            if (colors[neighbor] == -1) {
                pending.push(neighbor);
            }

            if (colors[neighbor] == 1) {
                red = false;
            }

            if (colors[neighbor] == 2) {
                blue = false;
            }
        }

        if (!red && !blue) {
            return false;
        }

        if (red) {
            colors[current] = 1;
        } else if (blue) {
            colors[current] = 2;
        }
    }

    return true;
}

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> colors(n, -1);

    cout << isBiPartite(graph, n, 0, colors) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}