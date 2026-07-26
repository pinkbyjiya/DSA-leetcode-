class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Step 1: Pehle array ko sort kar lo
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initially first 3 elements ka sum answer maan lete hain
        int closestSum = nums[0] + nums[1] + nums[2];

        // Step 2: Har element ko first element maan ke baaki 2 pointer lagao
        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int currentSum = nums[i] + nums[left] + nums[right];

                // Agar currentSum target ke aur close hai,
                // toh answer update kar do
                if(abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Agar exact target mil gaya
                // isse better answer possible hi nahi
                if(currentSum == target) {
                    return currentSum;
                }

                // Sum chhota hai target se
                // left ko aage badhao taaki sum increase ho
                else if(currentSum < target) {
                    left++;
                }

                // Sum bada hai target se
                // right ko peeche lao taaki sum decrease ho
                else {
                    right--;
                }
            }
        }

        // Sab possibilities check karne ke baad
        return closestSum;
    }
};