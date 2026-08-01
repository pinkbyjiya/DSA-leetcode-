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

    // Yeh function nums[left...right] se BST banayega
    TreeNode* build(vector<int>& nums, int left, int right)
    {
        // Base Case
        // Agar range khatam ho gayi hai to koi node nahi banegi
        if(left > right)
            return NULL;

        // Middle element ko root banao
        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // Left subtree banao
        root->left = build(nums, left, mid - 1);

        // Right subtree banao
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};