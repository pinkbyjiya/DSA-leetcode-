class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Make mid even so it points to the first element of a pair
            if (mid % 2 == 1) {
                mid--;
            }

            // Pair is correct: single element is on the right
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }
            
            // Pair is broken: single element is on the left
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};

//agar traverse krenge whole array ko TC humari o(n) ho jayegi but we want log n tc thats why we wrote this code 