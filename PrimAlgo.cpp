#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge
{
    int src;
    int dest;
    int weight;
};

struct Vertex
{
    int src;
    int distance;
    int parent;
    bool isVisited;
    vector<Edge*> neighbors;    
};

struct VertexGreaterThan {
    bool operator()(Vertex* a, Vertex* b) {
        return a->distance >= b->distance;
    }
};

void solution()
{
    int n, m;
    cin >> n >> m;

    vector<Vertex*> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        Vertex* newVertex = new Vertex();

        newVertex->src = i;
        newVertex->parent;
        newVertex->isVisited = false;
        newVertex->distance = INT_MAX;

        graph[i] = newVertex;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        Edge* edge = new Edge();
        edge->src = a;
        edge->dest = b;
        edge->weight = w;

        graph[a]->neighbors.push_back(edge);

        edge = new Edge();
        edge->src = b;
        edge->dest = a;
        edge->weight = w;

        graph[b]->neighbors.push_back(edge);
    }

    priority_queue<Vertex*, vector<Vertex*>, VertexGreaterThan> pending;

    graph[1]->distance = 0;
    graph[1]->parent = -1;
    pending.push(graph[1]);

    vector<Edge*> answer;

    while (!pending.empty()) {
        Vertex* current = pending.top();
        pending.pop();
        
        current->isVisited = true;

        for (int i = 0; i < current->neighbors.size(); i++) {
            Edge* edge = current->neighbors[i];
            Vertex* neighbor = graph[edge->dest];

            if (
                !neighbor->isVisited &&
                edge->weight < neighbor->distance
            ) {
                neighbor->distance = edge->weight;
                neighbor->parent = current->src;
                pending.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << graph[i]->parent << " " << i << " " << graph[i]->distance << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}