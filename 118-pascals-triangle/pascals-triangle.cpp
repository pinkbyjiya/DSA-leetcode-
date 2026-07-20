class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        // Final Pascal Triangle store karne ke liye
        vector<vector<int>> ans;

        // Har row ko ek-ek karke generate karenge
        for(int i = 0; i < numRows; i++)
        {
            // Current row me total (i+1) elements honge
            vector<int> row(i + 1);

            // Har row ka first aur last element hamesha 1 hota hai
            row[0] = 1;
            row[i] = 1;

            // Beech ke elements calculate karenge
            for(int j = 1; j < i; j++)
            {
                // Previous row ke do upar wale elements ka sum
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            // Current row ko answer me add kar do
            ans.push_back(row);
        }

        // Complete Pascal Triangle return kar do
        return ans;
    }
};