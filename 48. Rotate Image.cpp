class Solution {
public:
    // naive: find the transformation and generate a new matrix
    // O(mn) time & space, 10.57%
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int n = matrix.size();
        vector<vector<int>> rotate(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                rotate[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = rotate;
    }

    /*
     * clockwise rotate
     * first reverse up to down, then swap the symmetry
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */

    /*
     * anticlockwise rotate
     * first reverse left to right, then swap the symmetry
     * 1 2 3     3 2 1     3 6 9
     * 4 5 6  => 6 5 4  => 2 5 8
     * 7 8 9     9 8 7     1 4 7
    */

    // in-place: find the transformation and generate a new matrix
    // O(mn) time, O(1) space, 10.57%
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end()); // reverse up to down
        for(int i = 0; i < n; i++)  {
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
