class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            // Same old max/min chahiye for both calculations
            int oldMax = maxProduct;
            int oldMin = minProduct;

            // Current element se new max/min
            maxProduct = max({x, x * oldMax, x * oldMin});
            minProduct = min({x, x * oldMax, x * oldMin});

            // Overall maximum
            ans = max(ans, maxProduct);
        }

        return ans;
    }
};