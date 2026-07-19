class Solution {
public:
    int lengthOfLastWord(string s) {

        // Sabse pehle string ke last index pe jaate hain
        int i = s.length() - 1;

        // Agar end me spaces hain to unhe skip kar do
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Last word ki length store karne ke liye
        int count = 0;

        // Jab tak character space nahi hai tab tak count badhao
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        // Last word ki length return kar do
        return count;
    }
};