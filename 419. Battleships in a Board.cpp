class Solution {
public:
    // DFS: O(MN)time, O(MN)space, 3.93%
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty()) return 0;
        int row = board.size(), col = board[0].size();
        int count = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j]){
                    if(board[i][j] == '.') visited[i][j] = 1;
                    else{
                        count++;
                        dfs(board, visited, i, j);
                    }
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(visited[i][j]) return;
        visited[i][j] = 1;
        if(board[i][j] == 'X'){
            if(i > 0) dfs(board, visited, i - 1, j);
            if(i < board.size() - 1) dfs(board, visited, i + 1, j);
            if(j > 0) dfs(board, visited, i, j - 1);
            if(j < board[0].size() - 1) dfs(board, visited, i, j + 1);
        }
    }

    // Count the HEAD of the ship -> HEAD: an "X" grid without "X" int its above gird and left grid
    // O(MN) time, O(1) space, 22.05%, ok
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty()) return 0;
        int row = board.size(), col = board[0].size();
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'X' && (!i || board[i - 1][j] != 'X') && (!j || board[i][j - 1] != 'X'))
                    count++;
            }
        }
        return count;
    }
};
