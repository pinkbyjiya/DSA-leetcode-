class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int totalSum = 0;

        // Step 1: Calculate total sum
        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;

        // Step 2: Check every index
        for (int i = 0; i < nums.size(); i++) {

            // Right sum = total - left - current element
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            // Current element becomes part of left side
            leftSum += nums[i];
        }

        return -1;
    }
};