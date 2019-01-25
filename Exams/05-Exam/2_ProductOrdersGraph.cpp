#include <cmath>
#include <map>
#include <cstdio>
#include <queue>
#include <list>
#include <iostream>
#include <algorithm>

class Graph {
private:
    size_t V;
    std::list<int>* adj;
public:
    Graph(int N) {
        this->adj = new std::list<int>[N + 1];
        this->V = N + 1;
    }

    ~Graph() {
        delete[] this->adj;
    }

    void addEdge(int start, int end) {
        this->adj[start].push_back(end);
        this->adj[end].push_back(start);
    }

    int getTotalDistance(int start) {
        std::vector<bool> isVisited(this->V, false);
        std::vector<int> distances(this->V, 0);

        isVisited[start] = true;
        distances[start] = 0;

        std::queue<int> queue;
        queue.push(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            for (auto node : this->adj[current]) {
                if (!isVisited[node]) {
                    distances[node] = distances[current] + 1;
                    isVisited[node] = true;
                    queue.push(node);
                }
            }
        }

        int totalDistance = 0;
        for (int i = 0; i < this->V; i++) {
            if (distances[i] != 0) {
                totalDistance += distances[i];
            }
        }

        return totalDistance;
    }
};

int main() {
    int K = 0;
    std::cin >> K;

    Graph graph(K);
    for (int i = 0; i < K; i++) {
        int start = 0;
        int end = 0;
        std::cin >> start >> end;
        graph.addEdge(start, end);
    }

    int distance = graph.getTotalDistance(0);
    std::cout << distance << "\n";

    return 0;
}