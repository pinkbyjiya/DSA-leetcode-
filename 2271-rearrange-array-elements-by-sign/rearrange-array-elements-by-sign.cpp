class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> answer(n);

        int positiveIndex = 0;
        int negativeIndex = 1;

        for (int x : nums) {
            if (x > 0) {
                answer[positiveIndex] = x;
                positiveIndex += 2;
            }
            else {
                answer[negativeIndex] = x;
                negativeIndex += 2;
            }
        }

        return answer;
    }
};