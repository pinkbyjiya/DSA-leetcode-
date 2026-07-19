class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Final answer store karne ke liye
        vector<vector<int>> ans;

        // Sabse pehle array ko sort karenge
        // Sorting se two pointer approach use kar sakte hain
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Har element ko first element maan kar baaki 2 elements dhoondenge
        for(int i = 0; i < n - 2; i++)
        {
            // Agar same element dobara aa raha hai to skip kar do
            // Taaki duplicate triplets na aaye
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers
            int left = i + 1;
            int right = n - 1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                // Agar sum 0 hai to triplet mil gaya
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Left ke duplicate elements skip karo
                    while(left < right && nums[left] == nums[left + 1])
                        left++;

                    // Right ke duplicate elements skip karo
                    while(left < right && nums[right] == nums[right - 1])
                        right--;

                    // Dono pointers ko move karo
                    left++;
                    right--;
                }

                // Agar sum chhota hai to left badhao
                // Kyunki sorted array me bada number chahiye
                else if(sum < 0)
                {
                    left++;
                }

                // Agar sum bada hai to right ghatao
                // Kyunki chhota number chahiye
                else
                {
                    right--;
                }
            }
        }

        return ans;
    }
};