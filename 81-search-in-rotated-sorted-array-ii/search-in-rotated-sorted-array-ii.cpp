class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Target mil gaya
            if (nums[mid] == target) {
                return true;
            }

            // Duplicates ki wajah se sorted half identify nahi ho raha
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }

            // Left half sorted hai
            else if (nums[left] <= nums[mid]) {

                // Target left sorted half mein hai
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            // Right half sorted hai
            else {

                // Target right sorted half mein hai
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};