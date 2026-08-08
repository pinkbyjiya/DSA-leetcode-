class Solution {
public:

    // Backtracking function
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        // Agar target exactly 0 ho gaya,
        // iska matlab current combination ka sum target tha
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Agar index array ke end tak pahunch gaya
        // ya target negative ho gaya, toh return
        if (index >= candidates.size() || target < 0) {
            return;
        }

        // ------------------------------------------------
        // CASE 1: Current candidate ko choose karna
        // ------------------------------------------------

        // Agar current number target se chhota/equal hai,
        // toh hum ise combination mein add kar sakte hain.
        if (candidates[index] <= target) {

            current.push_back(candidates[index]);

            // IMPORTANT:
            // index ko same rakha hai because
            // ek number ko unlimited times use kar sakte hain.
            solve(candidates,
                  target - candidates[index],
                  index,
                  current,
                  ans);

            // Backtracking:
            // jo number add kiya tha usko remove kar do
            // taaki next possibilities try kar sakein.
            current.pop_back();
        }

        // ------------------------------------------------
        // CASE 2: Current candidate ko skip karna
        // ------------------------------------------------

        // Ab current number nahi lenge,
        // next candidate try karenge.
        solve(candidates,
              target,
              index + 1,
              current,
              ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;

        // Current combination ko store karne ke liye
        vector<int> current;

        // Backtracking start
        solve(candidates, target, 0, current, ans);

        return ans;
    }
};