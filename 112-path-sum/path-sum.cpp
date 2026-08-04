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

    bool hasPathSum(TreeNode* root, int targetSum) {

        // Base Case:
        // Agar tree hi empty hai to koi path exist hi nahi karega.
        if(root == NULL)
            return false;

        // Agar current node leaf node hai
        // (matlab iske left aur right dono NULL hain)
        if(root->left == NULL && root->right == NULL)
        {
            // Agar remaining target current node ke equal hai
            // to hume required path mil gaya.
            return (targetSum == root->val);
        }

        // Remaining target calculate karo
        int remainingSum = targetSum - root->val;

        // Left subtree me answer dhoondo
        bool leftAns = hasPathSum(root->left, remainingSum);

        // Right subtree me answer dhoondo
        bool rightAns = hasPathSum(root->right, remainingSum);

        // Agar kisi bhi side se true mila to answer true hoga
        return leftAns || rightAns;
    }
};