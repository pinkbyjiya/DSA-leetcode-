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
    int minDepth(TreeNode* root) {

        // Agar tree hi empty hai to depth 0 hogi
        if (root == NULL)
            return 0;

        // Agar current node leaf node hai
        // (matlab iske koi children nahi hain)
        if (root->left == NULL && root->right == NULL)
            return 1;

        // Left aur right subtree ki depth nikalenge
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // Agar left child exist nahi karta
        // to sirf right subtree ka answer valid hai
        if (root->left == NULL)
            return 1 + rightDepth;

        // Agar right child exist nahi karta
        // to sirf left subtree ka answer valid hai
        if (root->right == NULL)
            return 1 + leftDepth;

        // Agar dono children present hain
        // to minimum depth choose karenge
        return 1 + min(leftDepth, rightDepth);
    }
};