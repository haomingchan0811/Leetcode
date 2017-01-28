class Solution {
public:
    // cleverer way, check collision of row/column/block with one pass: O(N2), 82.39%
    bool isValidSudoku(vector<vector<char>>& board){
        int row[9][9] = {0};
        int column[9][9] = {0};
        int block[9][9] = {0};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                   int blockIdx = i / 3 * 3 + j / 3;  // key
                   int num = board[i][j] - '0' - 1;  // bug: index - 1
                    if(row[i][num] || column[j][num] || block[blockIdx][num])
                        return false;
                    else{
                        row[i][num] = 1;
                        column[j][num] = 1;
                        block[blockIdx][num] = 1;
                    }
                }
            }
        }
        return true;
    }

    // brute force, O(n2), 15.15%
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            unordered_map<char, int> check;
            for(int j = 0; j < col; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(check.find(num) == check.end())
                        check[num] = 1;
                    else return false;
                }
            }
        }
        for(int i = 0; i < col; i++){
            unordered_map<char, int> check;
            for(int j = 0; j < row; j++){
                if(board[j][i] != '.'){
                    int num = board[j][i] - '0';
                    if(check.find(num) == check.end())
                        check[num] = 1;
                    else return false;
                }
            }
        }

        int i = 0;
        int j = 0;
        while(i < row){
            int block_row = i + 3;
            for(int iteration = 0; iteration < 3; iteration++){
                unordered_map<char, int> check;
                int block_col = j + 3;
                for(; i < block_row; i++){
                    for(; j < block_col; j++){
                        // printf("row:%d, col:%d, num:%c\n", i, j, board[i][j]);
                        if(board[i][j] != '.'){
                            int num = board[i][j] - '0';
                            if(check.find(num) == check.end())
                              check[num] = 1;
                            else return false;
                        }
                    }
                    j = block_col - 3;
                }
                i = block_row - 3;
                j = block_col;
            }
            i = block_row;
            j = 0;
        }
        return true;
    }
};
