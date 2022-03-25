#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int dest;
    int weight;
};

struct Vertex {
    int src;
    int distance;
    vector<Edge*> neighbors;
};

struct VertexDistanceGreater {
    bool operator()(Vertex* a, Vertex* b) const {
        return a->distance >= b->distance;
    }
};

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<Vertex*> graph(n);

    for (int i = 0; i < n; i++) {
        Vertex* vertex = new Vertex();

        vertex->src = i;
        vertex->distance = INT_MAX;

        graph[i] = vertex;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        Edge* edge = new Edge();
        edge->dest = b;
        edge->weight = w;

        graph[a]->neighbors.push_back(edge);   

        edge = new Edge();
        edge->dest = a;
        edge->weight = w;
        graph[b]->neighbors.push_back(edge);
    }
    
    priority_queue<Vertex*, vector<Vertex*>, VertexDistanceGreater> pending;

    graph[0]->distance = 0;
    pending.push(graph[0]);

    while (!pending.empty()) {
        Vertex* minVertex = pending.top();
        pending.pop();
\
        for (int i = 0; i < minVertex->neighbors.size(); i++) {
            Edge* edge = minVertex->neighbors[i];
            Vertex* neighbor = graph[edge->dest];

            int distance = minVertex->distance + edge->weight;
            if (distance < neighbor->distance) {
                neighbor->distance = distance;
                pending.push(neighbor);
            }

        }
    }

    for (Vertex* v: graph) {
        cout << v->distance << " ";
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