class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Last digit se start karenge
        for (int i = digits.size() - 1; i >= 0; i--) {

            // Agar digit 9 se choti hai,
            // to usme 1 add karke answer return kar do
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Agar digit 9 hai to wo 0 ban jayegi
            // aur carry next digit me chali jayegi
            digits[i] = 0;
        }

        // Agar saare digits 9 the (jaise 999),
        // to starting me 1 insert kar do
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
// (Worst case me insert ki wajah se O(n) shifting hoti hai)