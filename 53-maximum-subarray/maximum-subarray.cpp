class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Start with the first element
        // because the subarray cannot be empty
        int currentSum = nums[0];

        // Stores the maximum sum found so far
        int maxSum = nums[0];

        // Start checking from the second element
        for(int i = 1; i < nums.size(); i++){

            // Decide:
            // 1. Continue the previous subarray
            // 2. Start a new subarray from nums[i]
            currentSum = max(nums[i], currentSum + nums[i]);

            // Update the best sum found so far
            maxSum = max(maxSum, currentSum);
        }

        // Return the maximum subarray sum
        return maxSum;
    }
};