class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for (int x : s) {
            // x is the start of a sequence
            if (s.count(x - 1) == 0) {
                int current = x;
                int length = 1;

                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};