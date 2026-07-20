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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Agar dono nodes NULL hain,
        // matlab dono trees is point tak same hain
        if(p == NULL && q == NULL)
            return true;

        // Agar sirf ek NULL hai aur dusra nahi,
        // to trees same nahi ho sakte
        if(p == NULL || q == NULL)
            return false;

        // Agar dono nodes ki values different hain,
        // to trees same nahi hain
        if(p->val != q->val)
            return false;

        // Ab recursively left subtree aur right subtree compare karenge
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};