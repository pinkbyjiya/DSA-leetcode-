class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // i batayega ki next valid element kaha rakhna hai
        int i = 0;

        // j pura array traverse karega
        for (int j = 0; j < nums.size(); j++) {

            // Agar current element val ke equal NAHI hai
            if (nums[j] != val) {

                // Us element ko front me copy kar do
                nums[i] = nums[j];

                // Agli valid position par move ho jao
                i++;
            }

            // Agar nums[j] == val hai
            // to simply ignore karo aur aage badh jao
        }

        // i hi valid elements ki count (k) hai
        return i;
    }
};