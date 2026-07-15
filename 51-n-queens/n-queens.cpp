class Solution {
public:

    // Ye check karega ki queen yaha rakh sakte hain ya nahi
    bool isSafe(int row, int col, vector<string>& board, int n){

        int x = row;
        int y = col;

        // Upper Left Diagonal check
        while(x >= 0 && y >= 0){

            if(board[x][y] == 'Q')
                return false;

            x--;
            y--;
        }

        x = row;
        y = col;

        // Left Side check
        while(y >= 0){

            if(board[x][y] == 'Q')
                return false;

            y--;
        }

        x = row;
        y = col;

        // Lower Left Diagonal check
        while(x < n && y >= 0){

            if(board[x][y] == 'Q')
                return false;

            x++;
            y--;
        }

        return true;
    }

    // Recursive function
    void solve(int col, vector<string>& board,
               vector<vector<string>>& ans, int n){

        // Agar saare columns complete ho gaye
        if(col == n){

            ans.push_back(board);
            return;
        }

        // Har row ko try karenge
        for(int row = 0; row < n; row++){

            // Agar safe hai tabhi queen rakhenge
            if(isSafe(row, col, board, n)){

                board[row][col] = 'Q';

                // Next column solve karo
                solve(col + 1, board, ans, n);

                // Backtracking
                // Wapas aate time queen hata do
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Empty board bana diya
        vector<string> board(n, string(n,'.'));

        solve(0, board, ans, n);

        return ans;
    }
};