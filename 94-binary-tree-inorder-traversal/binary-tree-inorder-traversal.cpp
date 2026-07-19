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

    // Inorder Traversal Function
    void inorder(TreeNode* root, vector<int>& ans) {

        // Agar node NULL hai to wapas aa jao
        if (root == NULL) {
            return;
        }

        // Pehle left subtree traverse karo
        inorder(root->left, ans);

        // Fir current node ki value answer me store karo
        ans.push_back(root->val);

        // Last me right subtree traverse karo
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        // Traversal ka answer store karne ke liye vector
        vector<int> ans;

        // Recursive function call
        inorder(root, ans);

        // Final inorder traversal return kar do
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)   // Recursive call stack + answer vector