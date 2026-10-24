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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Base case: no elements means no node
        if (nums.empty()) {
            return nullptr;
        }

        // Find the maximum element's position
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        // Create the root using the maximum value
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // Build the left subtree from elements before the maximum
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        root->left = constructMaximumBinaryTree(leftNums);

        // Build the right subtree from elements after the maximum
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
        root->right = constructMaximumBinaryTree(rightNums);

        // Return the constructed tree
        return root;
    }
};
