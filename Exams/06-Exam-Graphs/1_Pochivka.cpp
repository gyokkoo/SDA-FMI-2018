#include <iostream>
#include <vector>
#include <limits>

const long long LONG_MAX_VALUE = std::numeric_limits<long long>::max();

typedef std::pair<int, long long> iPair;

class Graph {
public:
    int V;
    int E;
    std::vector<iPair>* adj;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        this->adj = new std::vector<iPair>[V + 1];
    }

    ~Graph() {
        delete[] this->adj;
    }

    void addWeightedEdge(int u, int v, long long weight) {
        this->adj[u].emplace_back(std::make_pair(v, weight));
        this->adj[v].emplace_back(std::make_pair(u, weight));
    }

    long long* getDijkstraShortestPathsFrom(int startVertex) {
        long long* distances = new long long[this->V + 1];
        bool* isVisited = new bool[this->V + 1];

        for (int i = 0; i <= this->V; i++) {
            distances[i] = LONG_MAX_VALUE;
            isVisited[i] = false;
        }

        distances[startVertex] = 0;

        for (long long i = 1; i <= this->V; i++) {
            long long currentVertex = getMinDistanceVertexIndex(distances, isVisited);

            isVisited[currentVertex] = true;
            std::vector<iPair> current =  adj[currentVertex];

            for (auto pair : current) {
                long long weight = pair.second;
                long long nextVertex = pair.first;
                if (!isVisited[nextVertex] &&
                    distances[currentVertex] != LONG_MAX_VALUE &&
                    distances[currentVertex] + weight < distances[nextVertex]) {
                    distances[nextVertex] = distances[currentVertex] + weight;
                }
            }
        }

        return distances;
    }

private:
    long long getMinDistanceVertexIndex(const long long* distances, const bool* isVisited) {
        long long min = LONG_MAX_VALUE;
        int minVertex = 0;

        for (int v = 1; v <= this->V; v++) {
            if (!isVisited[v] && distances[v] <= min) {
                min = distances[v];
                minVertex = v;
            }
        }

        return minVertex;
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    int n = 0; // Vertices
    int m = 0; // Edges
    std::cin >> n >> m;
    Graph graph(n, m);

    for (int j = 0; j < m; j++) {
        int u = 0;
        int v = 0;
        long long w = 0;
        std::cin >> u >> v >> w;
        graph.addWeightedEdge(u, v, w);
    }

    int startVertex = 0;
    std::cin >> startVertex;

    long long* distances = graph.getDijkstraShortestPathsFrom(startVertex);

    for (long long vertex = 1; vertex <= n; vertex++) {
        if (vertex == startVertex) {
            continue;
        }

        if (distances[vertex] == LONG_MAX_VALUE) {
            std::cout << -1 << " ";
        } else {
            std::cout << distances[vertex] << " ";
        }
    }

    delete[] distances;
    std::cout << "\n";

    return 0;
}