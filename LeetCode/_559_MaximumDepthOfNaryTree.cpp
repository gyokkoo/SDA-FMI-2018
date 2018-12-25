/*
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 *
 * Given a n-ary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        std::vector<Node*> children = root->children;
        int max = 0;

        for (std::vector<Node*>::iterator it = children.begin();
                it != children.end(); ++it) {
            max = std::max(max, maxDepth(*it));
        }

        return max + 1;
    }
};