
class Solution {
public:
    bool search(vector<vector<char>>& board, string& word,
                int i, int j, int index) {

        // Step 1: Entire word matched
        if (index == word.size()) {
            return true;
        }

        // Step 2: Invalid position or wrong character
        if (i < 0 || j < 0 ||
            i >= board.size() ||
            j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }

        // Step 3: Temporarily mark this cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Step 4: Explore all four directions
        bool found =
            search(board, word, i + 1, j, index + 1) ||
            search(board, word, i - 1, j, index + 1) ||
            search(board, word, i, j + 1, index + 1) ||
            search(board, word, i, j - 1, index + 1);

        // Step 5: Undo the change (backtrack)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Try every cell as the starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        // No starting cell produced the word
        return false;
    }
};
