class Solution {
public:

    // Final answer store karne ke liye
    vector<vector<int>> ans;

    // Current permutation banane ke liye
    vector<int> current;

    // Recursive Backtracking Function
    void solve(vector<int>& nums, vector<bool>& used) {

        // Base Case:
        // Agar current permutation ki size nums ke equal ho gayi,
        // matlab ek complete permutation ready hai.
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Har index ko ek baar try karenge
        for (int i = 0; i < nums.size(); i++) {

            // ---------------------------------------------
            // Condition 1:
            // Agar ye element pehle hi use ho chuka hai
            // to isko dubara use nahi kar sakte.
            // ---------------------------------------------
            if (used[i])
                continue;

            // ---------------------------------------------
            // Condition 2:
            // Duplicate permutations avoid karne ke liye.
            //
            // Example:
            // nums = [1,1,2]
            //
            // Agar current wala 1 use nahi hua hai
            // aur previous wala same number abhi bhi available hai,
            // to current duplicate ko skip kar do.
            // ---------------------------------------------
            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1])
                continue;

            // ===== CHOOSE =====

            // Current element ko permutation me add karo
            current.push_back(nums[i]);

            // Mark karo ki ye element use ho gaya
            used[i] = true;

            // Agli position bharne ke liye recursion
            solve(nums, used);

            // ===== BACKTRACK =====

            // Wapas aate waqt mark hata do
            used[i] = false;

            // Last element remove karo taaki
            // dusri possibility explore kar sake
            current.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Sorting bahut important hai
        // Taaki duplicate numbers ek saath aa jaye
        sort(nums.begin(), nums.end());

        // Initially koi bhi element use nahi hua
        vector<bool> used(nums.size(), false);

        // Backtracking start
        solve(nums, used);

        return ans;
    }
};