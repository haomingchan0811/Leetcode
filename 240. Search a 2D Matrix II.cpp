class Solution {
public:
    // binary search for each row and column following the diagonal
    // O(min(M,N)*(logM+logN)), 11.84%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        for(int k = 0; k < min(m, n); k++){
            // binary search for the row starting with matrix[k][k]
            int head = k, tail = n - 1;
            while(head <= tail){
                int mid = head + (tail - head) / 2;
                int curr = matrix[k][mid];
                if(curr == target) return true;
                if(curr < target) head = mid + 1;
                else tail = mid - 1;
            }
            // binary search for the column starting with matrix[k][k]
            head = k, tail = m - 1;
            while(head <= tail){
                int mid = head + (tail - head) / 2;
                int curr = matrix[mid][k];
                if(curr == target) return true;
                if(curr < target) head = mid + 1;
                else tail = mid - 1;
            }
        }
        return false;
    }

    // binary search for each row: O(M*logN)), 17.92%
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            int head = 0, tail = n - 1;
            while(head <= tail){
                int mid = head + (tail - head) / 2;
                int curr = matrix[i][mid];
                if(curr == target) return true;
                if(curr < target) head = mid + 1;
                else tail = mid - 1;
            }
        }
        return false;
    }

    // starting from top-right, use the monotomous topology
    // O(M+N)), 95.54%, ok
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;     // key!!! starting from top-right, utilize monotomous order
        while(row < m && col >= 0){
            int curr = matrix[row][col];
            if(curr == target) return true;
            if(curr < target) row++;
            else col--;
        }
        return false;
    }
};
