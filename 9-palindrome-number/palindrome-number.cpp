class Solution {
public:
    bool isPalindrome(int x) {

        // Agar number negative hai to palindrome ho hi nahi sakta
        // Example: -121 reverse hoga 121-
        if (x < 0) {
            return false;
        }

        // Original number ko save kar liya compare karne ke liye
        int original = x;

        // Reverse number store karne ke liye
        long long reverseNum = 0;

        // Jab tak number 0 nahi ho jata
        while (x > 0) {

            // Last digit nikal lo
            int digit = x % 10;

            // Reverse number banao
            // Example:
            // 12 -> 12*10 + 3 = 123
            reverseNum = reverseNum * 10 + digit;

            // Last digit hata do
            x = x / 10;
        }

        // Agar reverse aur original same hain
        // to number palindrome hai
        return original == reverseNum;
    }
};