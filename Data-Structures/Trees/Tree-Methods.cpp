#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    // https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {

        std::vector<std::vector<int>> result;
        std::stack<std::vector<int>> stack;
        if (root == nullptr) {
            return result;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            std::vector<int> level;
            size_t queueSize = queue.size();
            for (size_t i = 0; i < queueSize; i++) {
                if (queue.front()->left != nullptr) {
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right != nullptr) {
                    queue.push(queue.front()->right);
                }
                level.push_back(queue.front()->val);
                queue.pop();
            }

            stack.push(level);
        }

        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }

    // https://leetcode.com/problems/same-tree/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        return (isSameTree(p->left, q->left)) && (q->val == p->val) &&
               (isSameTree(p->right, q->right));
    }

    // https://leetcode.com/problems/balanced-binary-tree/
    int treeDepth(TreeNode* root){
        if(root == nullptr) {
            return 0;
        }

        return std::max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int difference = std::abs(treeDepth(root->left) - treeDepth(root->right));
        if (difference > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    // https://leetcode.com/problems/minimum-depth-of-binary-tree/
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMinDepth = minDepth(root->left);
        int rightMinDepth = minDepth(root->right);
        if (leftMinDepth != 0 && rightMinDepth != 0) {
            return std::min(leftMinDepth, rightMinDepth) + 1;
        }

        if (leftMinDepth == 0) {
            return rightMinDepth + 1;
        }

        return leftMinDepth + 1;
    }

    // https://leetcode.com/problems/delete-node-in-a-bst/
    TreeNode* minValueNode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* current = root->right;
                delete root;
                return current;
            } else if (root->right == nullptr) {
                TreeNode* current = root->left;
                delete root;
                return current;
            }

            TreeNode* current = minValueNode(root->right);
            root->val = current->val;

            root->right = deleteNode(root->right, current->val);
        }

        return root;
    }

    // https://leetcode.com/problems/path-sum/
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }

        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            return true;
        } else if (root->val != sum && root->left == nullptr && root->right == nullptr) {
            return false;
        }

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};


int main() {
    TreeNode* p = new TreeNode(0);
    TreeNode* q = new TreeNode(0);
    Solution s;
    std::cout << s.isSameTree(p, q);

    return 0;
}
