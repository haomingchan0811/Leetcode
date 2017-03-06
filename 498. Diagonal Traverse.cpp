class Solution {
public:
    // brute force: O(mn)time & space, 44.81%, ok
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, up = 1, idx = 0;
        while(idx++ < m * n){
            ret.push_back(matrix[i][j]);
            if(up) {i--; j++;}
            else{i++; j--;}

            if(i == m) {up = 1; i = m - 1; j += 2;}
            if(j == n) {up = 0; j = n - 1; i += 2;}
            if(i < 0) {up = 0; i = 0;}
            if(j < 0) {up = 1; j = 0;}

        }
        return ret;
    }
};
