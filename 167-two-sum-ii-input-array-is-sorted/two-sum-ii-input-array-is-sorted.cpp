class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1; //1 based indexing hai

        while (left < right) { //Because hume do different elements chahiye

            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }

        return {};
    }
};