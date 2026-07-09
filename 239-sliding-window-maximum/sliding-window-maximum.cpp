class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            // Window se bahar wale index hata do
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Current se chhote elements ki zarurat nahi hai
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Current index add karo
            dq.push_back(i);

            // Window complete hone ke baad maximum answer me daal do
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};