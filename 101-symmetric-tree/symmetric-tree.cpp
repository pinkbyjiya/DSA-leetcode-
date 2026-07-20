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

    // Ye function check karega ki dono trees ek dusre ka mirror hain ya nahi
    bool isMirror(TreeNode* leftTree, TreeNode* rightTree)
    {
        // Agar dono NULL hain to symmetric hain
        if(leftTree == NULL && rightTree == NULL)
            return true;

        // Agar sirf ek NULL hai to symmetric nahi hai
        if(leftTree == NULL || rightTree == NULL)
            return false;

        // Agar values alag hain to bhi symmetric nahi hai
        if(leftTree->val != rightTree->val)
            return false;

        // Ab recursively mirror check karenge
        // Left tree ka left == Right tree ka right
        // Left tree ka right == Right tree ka left
        return isMirror(leftTree->left, rightTree->right) &&
               isMirror(leftTree->right, rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree hamesha symmetric hota hai
        if(root == NULL)
            return true;

        // Root ke left aur right subtree ko compare karenge
        return isMirror(root->left, root->right);
    }
};