class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        // Ye array prefixGcd store karega
        vector<int> prefixGcd(n);

        // Abhi tak ka maximum element
        int mx = 0;

        // Step 1:
        // prefixGcd array banana
        for(int i = 0; i < n; i++) {

            // Prefix ka maximum update karo
            mx = max(mx, nums[i]);

            // Current element aur prefix maximum ka gcd nikaalo
            prefixGcd[i] = __gcd(nums[i], mx);
        }

        // Step 2:
        // prefixGcd ko sort kar do
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        // Step 3:
        // Sabse chhota + sabse bada pair banao
        // Fir second smallest + second largest ...
        for(int i = 0; i < n / 2; i++) {

            // Pair ka gcd answer me add kar do
            ans += __gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }

        return ans;
    }
};