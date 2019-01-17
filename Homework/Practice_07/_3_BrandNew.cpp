#include <iostream>
#include <queue>
#include <list>

struct Node {
    int value;
    std::vector<int> children;
};

class Tree {
public:
    Node* nodes;

    Tree(int size) {
        this->nodes = new Node[size + 1];
    }

    void add(int first, int second) {
        this->nodes[first].children.push_back(second);
        this->nodes[second].children.push_back(first);
    }

    int getServiceCount(int maxCoffees, int* nodeValues) {
        std::queue<int> queue;
        int count = 0;
        nodes[1].value = 1;
        queue.push(1);
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            if (current != 1 && this->nodes[current].children.size() == 1 && nodeValues[current] <= maxCoffees) {
                count++;
            }

            for (int i = 0; i < nodes[current].children.size(); i++) {
                int nextCurrent = nodes[current].children[i];
                if (nodes[nextCurrent].value == 0) {
                    if (nodeValues[nextCurrent] == 0) {
                        queue.push(nextCurrent);
                    } else {
                        nodeValues[nextCurrent] += nodeValues[current];
                        if (nodeValues[nextCurrent] <= maxCoffees) {
                            queue.push(nextCurrent);
                        }
                    }

                    nodes[nextCurrent].value = 1;
                }
            }

        }

        return count;
    };
};

int main() {
    int N = 0;
    int M = 0;

    std::cin >> N;
    std::cin >> M;

    Tree tree(N);
    int nodeValues[100001];

    for (int i = 1; i <= N; i++) {
        std::cin >> nodeValues[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int first = 0;
        int second = 0;
        std::cin >> first >> second;

        tree.add(first, second);
    }

    int count = tree.getServiceCount(M, nodeValues);
    std::cout << count;

    return 0;
}