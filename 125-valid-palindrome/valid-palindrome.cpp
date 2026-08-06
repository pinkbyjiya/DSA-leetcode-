class Solution {
public:
    bool isPalindrome(string s) {

        // Left pointer starting se chalega
        int left = 0;

        // Right pointer end se chalega
        int right = s.length() - 1;

        // Jab tak dono pointers cross nahi karte
        while (left < right) {

            // Agar left wala character letter ya digit nahi hai
            // to usko ignore karke aage badh jao
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Agar right wala character letter ya digit nahi hai
            // to usko ignore karke peeche le aao
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Dono characters ko lowercase me convert karke compare karo
            if (tolower(s[left]) != tolower(s[right])) {

                // Agar match nahi hue to palindrome nahi hai
                return false;
            }

            // Match ho gaya to dono pointers ko move karo
            left++;
            right--;
        }

        // Agar pura string successfully compare ho gaya
        // to palindrome hai
        return true;
    }
};