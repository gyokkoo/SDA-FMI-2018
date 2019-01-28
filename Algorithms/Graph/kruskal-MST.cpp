#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSets {
public:
    int* parent;
    int* rank;
    int n;

    DisjointSets(int n) {
        this->n = n;
        this->parent = new int[n];
        this->rank = new int[n];

        for(int i = 0; i <= n; i++) {
            rank[i] = 0;

            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

class Graph {
public:
    int V;
    int E;

    std::vector<std::pair<int, std::pair<int, int>>> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST() {
        int weight = 0;

        std::sort(this->edges.begin(), this->edges.end());

        DisjointSets ds(this->V);

        std::vector< std::pair<int, std::pair<int, int>> >::iterator it;
        for (auto pair : this->edges) {
            int u = pair.second.first;
            int v = pair.second.second;

            int setU = ds.find(u);
            int setV = ds.find(v);

            if (setU != setV) {
                weight += pair.first;

                ds.merge(setU, setV);
            }
        }

        return weight;
    }
};

int main() {
    int N = 0; // Number of Nodes
    int M = 0; // Number of Edges

    std::cin >> N >> M;
    Graph g(N, M);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    std::cout << g.kruskalMST() << "\n";

    return 0;
}