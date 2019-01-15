/*
Даден е ориентиран и теглови граф с тегла цели числа. Да се намери дължината на най-дългия път от връх s до връх t. 
Смята се, че в графа няма цикли с положителна цена. 
Върховете на графа са номерирани с числата от 1 до n.

Input Format
На първия ред са зададени числата n, m, s, t
n - брой върхове в графа
m - брой ребра в графа
s - начален връх
t - краен връх

Следват m реда всеки обозначаващ ребро в графа и съдържащ три числа: v1 v2 w
v1 - начален връх на реброто
v2 - краен връх на реброто
w - тегло на реброто

Constraints:
1 <= n <= 1000
1 <= m <= 10000
-10^9 <= w <= 10^9

Output Format
На единствен ред изведете дължината на най-дългия път от s до t. 
Ако такъв път не съществува(тоест t не е достижим от s), то изведете -1.

Sample Input 0
4 5 1 2
1 2 4
1 3 1
3 2 1
3 4 2
4 2 2

Sample Output 0
5
*/

#include <iostream>
#include <vector>
#include <limits>

const long long LONG_MAX_VALUE = std::numeric_limits<long long>::max();

struct Edge {
public:
    int source;
    int destination;
    long long weight;

    Edge(int source, int destination, long long weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

class Graph {
public:
    int V;
    int E;
    std::vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addWeightedEdge(int u, int v, long long weight) {
        Edge edge(u, v, -weight);
        edges.push_back(edge);
    }

    long long getShortestPath(int startVertex, int endVertex) {
        long long* distances = new long long[this->V + 1];
        for (int i = 0; i <= this->V; i++) {
            distances[i] = LONG_MAX_VALUE;
        }

        distances[startVertex] = 0;

        for (int i = 0; i < this->V - 1; i++) {
            for (int j = 0; j < this->E; j++) {
               Edge currentEdge = this->edges[j];
               int u = this->edges[j].source;
               int v = this->edges[j].destination;
               long long weight = this->edges[j].weight;
               if (distances[u] != LONG_MAX_VALUE && distances[u] + weight < distances[v]) {
                   distances[v] = distances[u] + weight;
               }
            }
        }

        return distances[endVertex] == LONG_MAX_VALUE ? 1 : distances[endVertex];
    }
};

int main() {

    int n = 0; // Vertices
    int m = 0; // Edges
    int s = 0; // Start vertex
    int t = 0; // End vertex

    std::cin >> n >> m >> s >> t;

    Graph graph(n,m);
    for (int i = 0; i < m; i++) {
        int v1 = 0;
        int v2 = 0;
        long long weight = 0;
        std::cin >> v1 >> v2 >> weight;

        graph.addWeightedEdge(v1, v2, weight);
    }

    std::cout << -graph.getShortestPath(s, t) << "\n";

    return 0;
}