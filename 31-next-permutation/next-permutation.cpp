class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // Step 1: Find pivot
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If no pivot, this is the largest permutation
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element greater than pivot
        // Since suffix is decreasing, scan from right
        int j = nums.size() - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }

        // Swap pivot with just-greater element
        swap(nums[i], nums[j]);

        // Step 4: Make suffix smallest
        reverse(nums.begin() + i + 1, nums.end());
    }
};