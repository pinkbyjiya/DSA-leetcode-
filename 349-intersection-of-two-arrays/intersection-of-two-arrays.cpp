class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set;
        unordered_set<int> resultSet;
        vector<int> answer;

        // nums1 ke unique elements store karo
        for (int x : nums1) {
            set.insert(x);
        }

        // nums2 ko check karo
        for (int x : nums2) {
            if (set.count(x) && !resultSet.count(x)) {
                resultSet.insert(x);
                answer.push_back(x);
            }
        }

        return answer;
    }
};