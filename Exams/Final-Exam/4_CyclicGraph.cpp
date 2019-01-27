/*
Даден е насочен граф с тегла по ребрата. Да се напише функция, която проверява дали има цикъл в графа.

Input Format
N - брой тестове следват N на брой тестове всеки от който има: V E - брой върхове
и брой ребра xi yi wi - ребро между връх xi и връх yi с тегло wi

Constraints
1 < N < 20
1< V < 1000

Output Format
за всеки граф ако има цикъл се принтира true иначе falsе, резултатите се разделят с интервал.

Sample Input 0
2
3 5
3 1 4
2 3 4
3 2 2
1 3 2
2 1 1
3 5
1 3 1
1 2 4
2 3 3
3 1 3
3 2 4

Sample Output 0
true true
 */

#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    std::vector<int>* adj;
    int vertexes;
    int edges;
public:
    Graph(int V, int E) {
        this->vertexes = V;
        this->edges = E;
        this->adj = new std::vector<int>[V + 1];
    }

    ~Graph() {
        delete[] this->adj;
    }

    void addEdge(int u, int v) {
        this->adj[u].push_back(v);
    }

    bool isCycle() {
        std::vector<int> occurrences(this->vertexes + 1, 0);

        for (int u = 1; u <= this->vertexes; u++) {
            for (auto v : this->adj[u]) {
                occurrences[v]++;
            }
        }

        std::queue<int> queue;
        for (int i = 1; i <= this->vertexes; i++) {
            if (occurrences[i] == 0) {
                queue.push(i);
            }
        }

        int visitedCount = 0;
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            for (auto v : this->adj[current]) {
                occurrences[v]--;

                if (occurrences[v] == 0) {
                    queue.push(v);
                }
            }

            visitedCount++;
        }

        return visitedCount != this->vertexes;
    }
};

int main() {
    int N = 0;
    std::cin >> N;

    while (N > 0) {
        N--;

        int V = 0;
        int E = 0;
        std::cin >> V >> E;

        Graph graph(V, E);
        for (int i = 0; i < E; i++) {
            int u = 0;
            int v = 0;
            int weight = 0;

            // weight is ignored, no needed
            std::cin >> u >> v >> weight;

            graph.addEdge(u, v);
        }

        if (graph.isCycle()) {
            std::cout << "true ";
        } else {
            std::cout << "false ";
        }
    }
}