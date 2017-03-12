class Solution {
public:
    // cleverer way, check collision of row/column/block with one pass: O(N2), 82.39%
    // O(1)time & space, 47.51%, ok
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<int>> square(9, vector<int>(9, 0));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int index = i / 3 * 3 + j / 3;
                int num = board[i][j] - '0' - 1;
                if(rows[i][num] || cols[j][num] || square[index][num])
                    return false;
                rows[i][num] = 1; cols[j][num] = 1; square[index][num] = 1;
            }
        }
        return true;
    }
};
