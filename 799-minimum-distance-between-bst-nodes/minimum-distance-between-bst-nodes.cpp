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
    // Ye variable previous node ko store karega
    TreeNode* prev = NULL;

    // Isme minimum difference store hoga
    int ans = INT_MAX;

    // Inorder Traversal Function
    void inorder(TreeNode* root)
    {
        // Base Case
        if(root == NULL)
            return;

        // Step 1 : Left subtree visit karo
        inorder(root->left);

        // Step 2 : Current node process karo

        // Agar previous node exist karti hai,
        // to current aur previous ka difference nikal lo
        if(prev != NULL)
        {
            ans = min(ans, root->val - prev->val);
        }

        // Ab current node ko previous bana do
        prev = root;

        // Step 3 : Right subtree visit karo
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {

        // Inorder traversal call karo
        inorder(root);

        // Minimum difference return kar do
        return ans;
    }
};