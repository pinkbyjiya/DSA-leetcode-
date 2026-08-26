class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n, 1);

        // PASS 1: Left → Right
        int leftProduct = 1;

        for (int i = 0; i < n; i++) {

            // Current index ke left ka product
            answer[i] = leftProduct;

            // Current element ko next index ke left mein include karo
            leftProduct *= nums[i];
        }

        // PASS 2: Right → Left
        int rightProduct = 1;

        for (int i = n - 1; i >= 0; i--) {

            // Left product × Right product
            answer[i] *= rightProduct;

            // Current element ko next index ke right mein include karo
            rightProduct *= nums[i];
        }

        return answer;
    }
};