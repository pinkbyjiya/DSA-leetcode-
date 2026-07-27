class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        // n x n matrix banao aur sab jagah 0 bhar do
        vector<vector<int>> ans(n, vector<int>(n, 0));

        // Directions:
        // Right, Down, Left, Up
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        // Starting position
        int row = 0;
        int col = 0;

        // Shuru me Right direction me chalenge
        int dir = 0;

        // 1 se lekar n*n tak numbers fill karne hain
        for (int num = 1; num <= n * n; num++) {

            // Current cell me number bhar do
            ans[row][col] = num;

            // Next position calculate karo
            int newRow = row + dr[dir];
            int newCol = col + dc[dir];

            // Agar boundary ke bahar chale gaye
            // ya cell already filled hai
            if (newRow < 0 || newRow >= n ||
                newCol < 0 || newCol >= n ||
                ans[newRow][newCol] != 0) {

                // Direction change kar do
                dir = (dir + 1) % 4;

                // New direction ke hisaab se next position nikalo
                newRow = row + dr[dir];
                newCol = col + dc[dir];
            }

            // Next cell pe move karo
            row = newRow;
            col = newCol;
        }

        return ans;
    }
};