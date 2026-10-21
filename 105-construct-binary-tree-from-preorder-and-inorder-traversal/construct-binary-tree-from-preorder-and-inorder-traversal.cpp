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
    // Tracks the next root in preorder
    int preIndex = 0;

    // Maps each value to its position in inorder
    unordered_map<int, int> inorderIndex;

    TreeNode* build(vector<int>& preorder, int left, int right) {

        // No elements in this subtree
        if (left > right) {
            return nullptr;
        }

        // Preorder's next element is the root
        int rootValue = preorder[preIndex];
        preIndex++;

        // Create the root node
        TreeNode* root = new TreeNode(rootValue);

        // Find the root's position in inorder
        int mid = inorderIndex[rootValue];

        // Construct left subtree
        root->left = build(preorder, left, mid - 1);

        // Construct right subtree
        root->right = build(preorder, mid + 1, right);

        // Return the completed subtree
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store every inorder value's index
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Build the tree using the full inorder range
        return build(preorder, 0, inorder.size() - 1);
    }
};
