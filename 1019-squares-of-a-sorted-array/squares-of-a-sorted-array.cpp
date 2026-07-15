class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // nums.size() -> array ke total elements batata hai
        int n = nums.size();

        // Answer store karne ke liye ek n size ka vector bana diya.
        // Abhi saare elements automatically 0 honge.
        vector<int> ans(n);

        // left pointer array ke starting se start hoga.
        int left = 0;

        // right pointer array ke end se start hoga.
        int right = n - 1;

        // index answer array ke last index se start hoga.
        // Kyuki sabse bada square last me store karna hai.
        int index = n - 1;

        // Jab tak left aur right ek dusre ko cross nahi karte
        // tab tak loop chalega.
        while (left <= right) {

            // abs() -> absolute value deta hai.
            // Example:
            // abs(-5) = 5
            // abs(5) = 5

            // Agar left side ka absolute value bada hai...
            if (abs(nums[left]) > abs(nums[right])) {

                // left wale number ka square answer me store karo.
                // nums[left] * nums[left] matlab square.
                ans[index] = nums[left] * nums[left];

                // left wala element use ho chuka hai,
                // isliye left pointer ko aage badha do.
                left++;
            }
            else {

                // Agar right side bada ya equal hai,
                // to uska square store kar do.
                ans[index] = nums[right] * nums[right];

                // right wala element use ho gaya.
                // Pointer ko ek step left le aao.
                right--;
            }

            // Humne answer ka ek position fill kar diya.
            // Ab next bada square uske pehle aayega.
            index--;
        }

        // Final sorted squares return kar do.
        return ans;
    }
};