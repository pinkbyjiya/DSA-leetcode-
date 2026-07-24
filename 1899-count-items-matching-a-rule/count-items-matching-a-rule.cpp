class Solution {
public:
    int countMatches(vector<vector<string>>& items, string key, string value) {
        int i = key == "type" ? 0 : key == "color" ? 1 : 2, ans = 0;

        for (auto &x : items)
            ans += (x[i] == value);

        return ans;
    }
};