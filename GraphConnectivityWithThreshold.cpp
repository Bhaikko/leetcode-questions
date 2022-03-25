#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(
    vector<int> graph[], 
    vector<bool>& isVisited, 
    int currentVertex, 
    int endVertex,
    bool& hasPath
) {
    isVisited[currentVertex] = true;

    if (currentVertex == endVertex) {
        hasPath = true;
        return;
    }

    if (hasPath) {
        return;
    }

    for (int i = 0; i < graph[currentVertex].size(); i++) {
        int neibour = graph[currentVertex][i];

        if (!isVisited[neibour]) {
            dfs(graph, isVisited, neibour, endVertex, hasPath);
        }
    }
}

void solution()
{
    int n, t;
    cin >> n >> t;

    vector<int> graph[n + 1];

    int q;
    cin >> q;

    int queries[2 * q];
    for (int i = 0; i < q; i++) {
        cin >> queries[2 * i + 0] >> queries[2 * i + 1];

        if (__gcd(
            queries[2 * i + 0],
            queries[2 * i + 1] 
        ) > t) {
            graph[queries[2 * i + 0]].push_back(queries[2 * i + 1]);
            graph[queries[2 * i + 1]].push_back(queries[2 * i + 0]);
        }
    } 

    for (int i = 0; i < q; i++) {
        vector<bool> isVisited(n + 1, false);
        bool hasPath = false;

        dfs(graph, isVisited, queries[2 * i + 0], queries[2 * i + 1], hasPath);

        cout << hasPath << endl;
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}