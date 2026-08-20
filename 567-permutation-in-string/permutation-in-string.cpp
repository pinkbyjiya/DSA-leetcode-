class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Agar s1 bada hai toh permutation possible hi nahi
        if (s1.length() > s2.length()) {
            return false;
        }

        // s1 aur current window ki character frequencies
        int freq1[26] = {0};
        int freq2[26] = {0};

        // s1 ki frequency count karo
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }

        // s2 ki first window ki frequency
        // window size = s1 ki length
        for (int i = 0; i < s1.length(); i++) {
            freq2[s2[i] - 'a']++;
        }

        // First window check karo
        bool same = true;

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                same = false;
                break;
            }
        }

        if (same) {
            return true;
        }

        // Ab window slide karenge
        for (int i = s1.length(); i < s2.length(); i++) {

            // Purana character window se bahar
            freq2[s2[i - s1.length()] - 'a']--;

            // Naya character window mein andar
            freq2[s2[i] - 'a']++;

            // Current window ko s1 ki frequency se compare karo
            same = true;

            for (int j = 0; j < 26; j++) {
                if (freq1[j] != freq2[j]) {
                    same = false;
                    break;
                }
            }

            // Same frequencies = permutation found
            if (same) {
                return true;
            }
        }

        return false;
    }
};