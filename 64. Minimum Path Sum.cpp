#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // dynamic programming: 12ms
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int matrix[row][col];
        matrix[0][0] = grid[0][0];
        for(int i = 1; i < row; i++) matrix[i][0] = matrix[i - 1][0] + grid[i][0]; // initialize the first column
        for(int j = 1; j < col; j++) matrix[0][j] = matrix[0][j - 1] + grid[0][j]; // initialize the first row
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + grid[i][j];
            }
        }
        return matrix[row - 1][col - 1];
    }
};
