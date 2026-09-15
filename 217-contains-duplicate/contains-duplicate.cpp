class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            
            // Agar number pehle se present hai
            if (seen.count(nums[i])) {
                return true;
            }

            // Number ko HashSet mein store karo
            seen.insert(nums[i]);
        }

        // Koi duplicate nahi mila
        return false;
    }
};