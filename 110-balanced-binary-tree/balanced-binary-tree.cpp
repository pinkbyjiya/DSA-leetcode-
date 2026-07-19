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

    // Ye function tree ki height return karega.
    // Agar tree balanced nahi hua to -1 return karega.
    int height(TreeNode* root) {

        // Empty tree ki height 0 hoti hai
        if (root == NULL) {
            return 0;
        }

        // Left aur right subtree ki height nikal lo
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Agar kisi bhi side pehle se unbalanced hai,
        // to seedha -1 return kar do.
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // Agar height difference 1 se zyada hai,
        // to tree balanced nahi hai.
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Warna current node ki height return kar do.
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {

        // Agar height -1 nahi aayi,
        // matlab tree balanced hai.
        return height(root) != -1;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(h)