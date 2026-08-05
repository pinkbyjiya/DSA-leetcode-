class Solution {
public:
    string addBinary(string a, string b) {

        // Dono strings ke last index se start karenge
        int i = a.length() - 1;
        int j = b.length() - 1;

        // Carry initially 0 hoga
        int carry = 0;

        // Final answer is string me store hoga
        string ans = "";

        // Jab tak kisi bhi string me character bacha hai
        // ya carry bachi hai, tab tak loop chalayenge
        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            // Agar a me character bacha hai to uski value add kar do
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // Agar b me character bacha hai to uski value add kar do
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Current binary digit answer me add kar do
            ans += (sum % 2) + '0';

            // Next iteration ke liye carry update kar do
            carry = sum / 2;
        }

        // Answer reverse order me bana tha,
        // isliye usse reverse kar denge
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Time Complexity : O(max(a.length(), b.length()))
// Space Complexity : O(max(a.length(), b.length()))