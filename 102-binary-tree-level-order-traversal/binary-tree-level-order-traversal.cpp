/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Store all levels
        vector<vector<int>> ans;

        // If tree is empty, return empty answer
        if (root == nullptr) return ans;

        // Queue stores nodes waiting to be processed
        queue<TreeNode*> q;

        // Start with the root node
        q.push(root);

        // Process the tree level by level
        while (!q.empty()) {

            // Number of nodes in the current level
            int size = q.size();

            // Store values of this level
            vector<int> level;

            // Process only current-level nodes
            for (int i = 0; i < size; i++) {

                // Get the first node
                TreeNode* node = q.front();
                q.pop();

                // Add its value to the current level
                level.push_back(node->val);

                // Add left child if it exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Add right child if it exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Add the completed level to the answer
            ans.push_back(level);
        }

        return ans;
    }
};
