#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int findParent(vector<int>& parent, int ele)
{
    int currParent = parent[ele];
    while (currParent != parent[currParent]) {
        
        currParent = parent[currParent];
    }

    return currParent;
}

void unionSet(vector<int>& parent, vector<int>& rank, int a, int b)
{
    int parentA = findParent(parent, a);
    int parentB = findParent(parent, b);

    parent[a] = parentA;
    parent[b] = parentB;

    int rankA = rank[parentA];
    int rankB = rank[parentB];

    if (rankA == rankB) {
        if (parentA > parentB) {
            swap(parentA, parentB);
        }

        parent[parentA] = parentB;
        rank[parentA]++; 

    } else {
        if (rankA < rankB) {
            parent[parentB] = parentA;
        } else {
            parent[parentA] = parentB;
        }
    }
}

struct Edge {
    int src;
    int dest;
    int weight;
};

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> graph(m);
    for (int i = 0; i < m; i++) {
        int src, dest, w;
        cin >> src >> dest >> w;

        graph[i].src = src;
        graph[i].dest = dest;
        graph[i].weight = w;
    }
    
    vector<int> parent(n + 1),
                rank(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    sort(graph.begin(), graph.end(), [](Edge a, Edge b) -> bool {
        return a.weight < b.weight;
    });

    vector<Edge> answer;

    for (int i = 0; i < m; i++) {
        Edge currEdge = graph[i];

        int parentA = findParent(parent, currEdge.src);
        int parentB = findParent(parent, currEdge.dest);

        if (parentA != parentB) {
            answer.push_back(currEdge);
            unionSet(parent, rank, parentA, parentB);
        }
    }

    for (Edge e: answer) {
        cout << e.src << " " << e.dest << " " << e.weight << endl;
    }

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}