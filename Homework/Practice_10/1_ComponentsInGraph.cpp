/*
 * https://www.hackerrank.com/challenges/components-in-graph/problem
 */

#include <iostream>
#include <vector>

int componentCount = 0;

void DFS(int start, bool* visited, std::vector<int>* graph) {
    visited[start] = true;
    componentCount++;

    for (int i : graph[start]) {
        if (!visited[i]) {
            DFS(i, visited, graph);
        }
    }
}

int main() {
    int N = 0;
    std::cin >> N;

    std::vector<int> graph[30001];
    bool visited[30001] = { false };

    for (int i = 0; i < N; i++) {
        int first = 0;
        int second = 0;

        std::cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    int minSize = 15001;
    int maxSize = 0;
    for (int j = 0; j < 2 * N; j++) {
        if (!visited[j]) {
            DFS(j, visited, graph);

            if (minSize >= componentCount && componentCount != 1) {
                minSize = componentCount;
            }

            if (maxSize <= componentCount) {
                maxSize = componentCount;
            }

            componentCount = 0;
        }
    }

    std::cout << minSize << " " << maxSize << "\n";

    return 0;
}