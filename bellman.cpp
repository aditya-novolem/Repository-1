#include<iostream>
#include<vector>
using namespace std;

#define INF 0x3f3f3f3f

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int v, int e) : V(v), E(e) {}

    void add_edge(int u, int v, int w) {
        Edge edge = {u, v, w};
        edges.push_back(edge);
    }

    void bellman_ford(int src) {
        vector<int> dist(V, INF);
        dist[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (auto edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;
                if (dist[u] != INF && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (auto edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }

        cout << "Vertex Distance from Source\n";
        for (int i = 0; i < V; ++i)
            cout << i << "\t\t" << dist[i] << endl;
    }
};

int main() {
    Graph g(5, 8);
    g.add_edge(0, 1, -1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 2);
    g.add_edge(3, 2, 5);
    g.add_edge(3, 1, 1);
    g.add_edge(4, 3, -3);
    g.bellman_ford(0);
    return 0;
}
