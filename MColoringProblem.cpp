#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool FillColor(
    vector<vector<bool>>& graph, 
    int currentVertex, 
    int currentNeighbor,
    int n,
    unordered_map<int, int>& colors,
    int& num
) {
    
    if (currentVertex == n + 1) {
        num = min(num, int(colors.size()));
        return true;
    }

    if (currentNeighbor == n + 1) {
        return FillColor(graph, currentVertex + 1, 1, n, colors, num);
    }

    if (
        currentVertex == currentNeighbor || 
        graph[currentVertex][currentNeighbor] == false    
    ) {
        return FillColor(graph, currentVertex, currentNeighbor + 1, n, colors, num);
    }
    
    // cout << currentVertex << " " << currentNeighbor << endl;
    for (int c = 1; c <= n; c++) {
        if (colors.find(currentNeighbor) != colors.end()) {
            if (colors[currentNeighbor] != c) {
                colors[currentVertex] = c;
                if (FillColor(graph, currentVertex, currentNeighbor + 1, n, colors, num)) {
                    return true;
                }

                colors.erase(currentVertex);
                // continue;
            }
        } 

    }

    return false;
}

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1));
    unordered_map<int, int> colors;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool a;
            cin >> a;
            graph[i][j] = a;
            graph[j][i] = a;
        }
    }

    int ans = INT_MAX;

    FillColor(graph, 1, 1, n, colors, ans);
    set<int> distinctColors;
    for (auto itr: colors) {
        // cout << itr.first << " " << itr.second << endl;
        distinctColors.insert(itr.second);
    }

    // cout << ans << endl;

    cout << (distinctColors.size() <= m ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }

    // solution();

    return 0;
}