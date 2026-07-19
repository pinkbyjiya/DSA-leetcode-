class Solution {
public:
    int climbStairs(int n) {

        // Agar sirf 1 ya 2 stairs hain to answer wahi hoga
        if (n <= 2) {
            return n;
        }

        // prev1 -> n-2 stairs ka answer
        // prev2 -> n-1 stairs ka answer
        int prev1 = 1;
        int prev2 = 2;

        // 3rd stair se lekar nth stair tak answer nikalte hain
        for (int i = 3; i <= n; i++) {

            // Current stair tak pahunchne ke total ways
            int curr = prev1 + prev2;

            // Values ko next iteration ke liye update kar do
            prev1 = prev2;
            prev2 = curr;
        }

        // Last stair ka answer return kar do
        return prev2;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)