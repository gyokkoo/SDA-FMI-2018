/*
 * https://www.hackerrank.com/challenges/bfsshortreach/problem
 *
 * Time Complexity: O(V + E)
 */

#include <iostream>
#include <vector>
#include <queue>

void solveBFS(std::vector<int>* edges, int* distances, int start) {
    bool visited[1000] = { false };
    std::queue<int> queue;

    queue.push(start);
    distances[start] = 0;
    visited[start] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        for (auto& item : edges[current]) {
            if (!visited[item]) {
                visited[item] = true;
                distances[item] = distances[current] + 1;
                queue.push(item);
            }
        }
    }
}

int main() {
    int Q = 0;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        std::vector<int> graph[1000];
        int distances[1000] = { -1 };

        int vertexCount = 0;
        int edgesCount = 0;
        std::cin >> vertexCount >> edgesCount;

        for (int j = 0; j < edgesCount; j++) {
            int u = 0;
            int v = 0;
            std::cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int startNode = 0;
        std::cin >> startNode;

        solveBFS(graph, distances, startNode);

        for (int node = 1; node <= vertexCount; node++) {
            if (node != startNode) {
                if (distances[node] > 0) {
                    std::cout << distances[node] * 6 << " ";
                } else {
                    std::cout << -1 << " ";
                }
            }
        }

        std::cout << "\n";
    }

    return 0;
}
