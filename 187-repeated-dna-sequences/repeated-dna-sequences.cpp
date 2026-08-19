class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string, int> freq;
        vector<string> ans;

        int n = s.length();

        // Har possible 10-character window check karo
        for (int i = 0; i <= n - 10; i++) {

            // Current 10-character sequence
            string sub = s.substr(i, 10);

            // Is sequence ki frequency badhao
            freq[sub]++;

            // Second time mili = repeated sequence
            if (freq[sub] == 2) {
                ans.push_back(sub);
            }
        }

        return ans;
    }
};