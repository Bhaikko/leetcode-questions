#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int source;
    int destination;
    int weight;
};

int find(int link[], int n, int x) {
    while (x != link[x]) {
        x = link[x];
    }

    return x;
}

bool hasSameRepresentative(int link[], int n, int a, int b) {
    return find(link, n, a) == find(link, n, b);
}

void unite(int link[], int size[], int n, int a, int b) 
{
    a = find(link, n, a);
    b = find(link, n, b);

    if (size[a] < size[b]) {
        swap(a, b);
    }

    size[a] += size[b];
    link[b] = a;
}
    
int minCostConnectPoints(vector<vector<int>>& points) {
    vector<Edge> edges;
    int n = points.size();

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            Edge newEdge;
            newEdge.source = i + 1;
            newEdge.destination = j + 1;
            newEdge.weight = 
                abs(points[i][0] - points[j][0]) + 
                abs(points[i][1] - points[j][1]);

            edges.push_back(newEdge);
        }
        
    }

    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].source << " " << edges[i].destination << " " << edges[i].weight << endl;
    }

    // cout << edges.size() << endl;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> bool {
        return a.weight <= b.weight;
    });

    int link[n + 1], size[n + 1];
    for (int i = 1; i <= n; i++) {
        link[i] = i;
        size[i] = 1;
    }

    Edge mst[n - 1];
    int count = 0;

    for (int i = 0; i < edges.size(); i++) {
        Edge currentEdge = edges[i];

        if (!hasSameRepresentative(link, n, currentEdge.source, currentEdge.destination)) {
            mst[count++] = currentEdge;
            unite(link, size, n, currentEdge.source, currentEdge.destination);
        }
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += mst[i].weight;
    }

    return sum;
    



}

void solution()
{
    // cout << minCostConnectPoints
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
    return 0;
}