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
    int maxDepth(TreeNode* root) {

        // Base case: empty tree
        if (root == nullptr) {
            return 0;
        }

        // Find left subtree depth
        int leftDepth = maxDepth(root->left);

        // Find right subtree depth
        int rightDepth = maxDepth(root->right);

        // Return greater depth + current node
        return 1 + max(leftDepth, rightDepth);
    }
};
