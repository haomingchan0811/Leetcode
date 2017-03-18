class Solution {
public:
    // record flag: O(mn)time & space, 59.35%, ok
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        vector<vector<int>> notZero = matrix;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(notZero[i][j]) continue;
                if(!rows[i]){
                    for(int k = 0; k < n; k++)
                        matrix[i][k] = 0; 
                    rows[i] = 1;
                }
                if(!cols[j]){
                    for(int k = 0; k < m; k++)
                        matrix[k][j] = 0;
                    cols[j] = 1;
                }
            }
        }
    }
    
    // hashset: record the rows and cols that has a member of 0, then set corresponding 0 in the second iteraiton
    // O(mn)time, O(m+n)space, 59.35%, ok
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> rows, cols;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto i = rows.begin(); i != rows.end(); i++)
            for(int j = 0; j < n; j++)
                matrix[*i][j] = 0;
                
        for(auto i = cols.begin(); i != cols.end(); i++)
            for(int j = 0; j < m; j++)
                matrix[j][*i] = 0;
    }
    
    // first elem in each row to indicate whether this row has 0, likewise, first elem in each col ...
    // !!! review, O(mn)time, O(1)space, 85.20%, ok
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int col0 = 1;  // indicate whether first col has 0 (because of overlap of 1st row and 1st col)
        for(int i = 0; i < m; i++){
            if(!matrix[i][0]) col0 = 0;
            for(int j = 1; j < n; j++){
                if(!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        // BUG: should be bottom-right to top-left, avoid collision 
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 1; j--){
                if(!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
            if(!col0) matrix[i][0] = 0;
        }
    }
};