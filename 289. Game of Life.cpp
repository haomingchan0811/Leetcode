class Solution {
public:
    // brute force: O(mn) time & space, 48.39%, ok
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> ret(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int live = 0;
                for(int x = i - 1; x <= i + 1; x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        if(x >= 0 && x < row && y >= 0 && y < col && !(x == i && y == j))
                            live += board[x][y];
                    }
                }
                if(live == 3 || (board[i][j] && live == 2))
                    ret[i][j] = 1;
                else ret[i][j] = 0;
            }
        }
        board = ret;
    }

    // use 2 bit to represent 2 states and shift to the right after one iteration
    // O(mn) time, O(1) space, 48.39%, ok
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int live = -board[i][j];   // clever way of initialization, save the check later
                for(int x = max(i - 1, 0); x < min(row, i + 2); x++){
                    for(int y = max(j - 1, 0); y < min(col, j + 2); y++){
                        // bug: "live += board[x][y]:, should only check the rightmost bit
                        live += board[x][y] & 1;
                    }
                }
                if(live == 3 || (board[i][j] && live == 2))
                    board[i][j] |= 2;       // set the new bit: 00->10, 01->11
            }
        }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                board[i][j] >>= 1;  // shift to the right, save the leftmost as the current value
    }
};
