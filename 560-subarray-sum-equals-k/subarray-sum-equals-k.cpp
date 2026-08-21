class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // prefixSum -> kitni baar ye prefix sum aaya
        unordered_map<int, int> freq;

        // Prefix sum 0 initially ek baar maana
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Current prefix sum
            prefixSum += nums[i];

            // Hume previous prefix sum chahiye:
            // prefixSum - previous = k
            // previous = prefixSum - k
            int required = prefixSum - k;

            // Agar required prefix pehle aaya hai,
            // utni subarrays ka sum k hoga
            if (freq.find(required) != freq.end()) {
                count += freq[required];
            }

            // Current prefix sum ko map mein store karo
            freq[prefixSum]++;
        }

        return count;
    }
};