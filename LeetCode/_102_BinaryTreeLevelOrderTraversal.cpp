/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> nodesToTraverse;
        nodesToTraverse.push(root);
        
        while (!nodesToTraverse.empty()) {
            vector<int> currentLevel;
            int size = nodesToTraverse.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = nodesToTraverse.front();
                nodesToTraverse.pop();
                currentLevel.push_back(current->val);
                if (current->left) {
                    nodesToTraverse.push(current->left);
                }
                if (current->right) {
                    nodesToTraverse.push(current->right);
                }
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
};