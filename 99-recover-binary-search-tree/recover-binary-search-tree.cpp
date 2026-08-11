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

    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    // Inorder traversal BST ko sorted order mein visit karta hai
    void inorder(TreeNode* root) {

        // Agar node NULL hai toh return
        if (root == NULL)
            return;

        // Pehle left subtree visit karo
        inorder(root->left);

        // Agar previous node ka value current se bada hai,
        // matlab BST ka order break ho raha hai
        if (prev != NULL && prev->val > root->val) {

            // Pehli baar order break hua
            if (first == NULL) {
                first = prev;
            }

            // Current node doosra wrong node ho sakta hai
            second = root;
        }

        // Current node ko previous bana do
        prev = root;

        // Ab right subtree visit karo
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        // Inorder traversal se dono swapped nodes find karenge
        inorder(root);

        // Dono nodes ke values swap kar do
        swap(first->val, second->val);
    }
};