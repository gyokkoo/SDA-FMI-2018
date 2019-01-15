/*
По даден неорентиран и теглови граф и начален връв s, намерете най-късия път от s до всеки от върховете в графа.
Всички ребра в графа имат неотрицателно тегло.

Input Format

На първия ред е зададено числото t - броя тестове. Всеки тест се състои от:

На първия ред са дадени числата n и m - броя на върховете и ребрата в графа.
Всеки от следващите m реда съдържа числата u v w, съответващи на неорентирано ребро (u, v) с тегло w.
На последния ред е зададено числото s - началния връх.
Върховете в графа са номерирани с числата от 1 до n.

Constraints:
1 <= t <= 10

1 <= n, m, <= 2 * 10^5

0 <= w <= 10^9

Output Format

За всеки тест на нов ред изведете dist[0] dist[1] ... dist[s-1] dist[s+1] ... dist[n], където dist[i] е най-късия път
от s до i. Ако такъв път не съществува(тоест i не е достижим от s), то dist[i] = -1

Sample Input 0

1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
Sample Output 0

24 3 15

 */

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

    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
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
    }

    return 0;
}