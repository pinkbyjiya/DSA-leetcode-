class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            // Find middle index
            int mid = left + (right - left) / 2;

            // We are going uphill
            if (nums[mid] < nums[mid + 1]) {
                // Peak must be on the right
                left = mid + 1;
            }

            // We are going downhill
            else {
                // Peak can be mid itself or on the left
                right = mid;
            }
        }

        // left == right, only one candidate remains
        return left;
    }
};