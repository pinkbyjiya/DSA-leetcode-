/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Ye vector answer store karega
    vector<int> ans;

    // Recursive function jo preorder traversal karega
    void preorder(TreeNode* root)
    {
        // Base Case:
        // Agar node NULL hai to kuch bhi nahi karna
        if(root == NULL)
            return;

        // Step 1: Sabse pehle current node ko visit karo
        ans.push_back(root->val);

        // Step 2: Left subtree ko preorder se traverse karo
        preorder(root->left);

        // Step 3: Right subtree ko preorder se traverse karo
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        // Root se traversal start karo
        preorder(root);

        // Final answer return kar do
        return ans;
    }
};