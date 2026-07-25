class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Step 1:
        // Sabse pehle intervals ko unke starting point ke according sort kar do.
        // Eg: [[8,10],[1,3],[2,6]] -> [[1,3],[2,6],[8,10]]
        sort(intervals.begin(), intervals.end());

        // Final merged intervals yaha store honge.
        vector<vector<int>> ans;

        // Step 2:
        // Har interval ko ek-ek karke process karo.
        for(auto interval : intervals)
        {
            // Agar answer empty hai
            // ya current interval previous wale se overlap nahi karta
            // to directly push kar do.
            if(ans.empty() || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                // Agar overlap karta hai
                // to previous interval ka end update kar do.
                // End hamesha maximum hoga.
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};