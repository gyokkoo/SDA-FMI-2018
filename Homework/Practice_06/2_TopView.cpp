/*
class Node {int , int
     public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

void topView(Node * root) {
    if (root == nullptr) {
        return;
    }

    std::queue<int> positions;
    std::queue<Node*> nodes;
    std::map<int, int> topView;

    positions.push(0);
    nodes.push(root);

    while (nodes.size()) {
        Node* currentNode = nodes.front();
        nodes.pop();
        int currentPosition = positions.front();
        positions.pop();

        if (currentNode != nullptr) {
            if (!topView.count(currentPosition)) {
                topView[currentPosition] = currentNode->data;
            }

            positions.push(currentPosition - 1);
            positions.push(currentPosition + 1);
            nodes.push(currentNode->left);
            nodes.push(currentNode->right);
        }
    }

    for (const auto& pair : topView) {
        std::cout << pair.second << " ";
    }
}