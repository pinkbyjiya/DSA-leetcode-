class Solution {
public:
    vector<int> getRow(int rowIndex) {

        // Pehli row hamesha [1] hoti hai
        vector<int> row = {1};

        // Row 1 se lekar rowIndex tak saari rows banayenge
        for(int i = 1; i <= rowIndex; i++) {

            // Current row banane ke liye vector
            vector<int> newRow(i + 1);

            // Har row ka pehla aur last element hamesha 1 hota hai
            newRow[0] = 1;
            newRow[i] = 1;

            // Beech ke elements previous row ke do adjacent elements ka sum hote hain
            for(int j = 1; j < i; j++) {
                newRow[j] = row[j - 1] + row[j];
            }

            // Ab current row ko previous row bana do
            row = newRow;
        }

        // Required row return kar do
        return row;
    }
};