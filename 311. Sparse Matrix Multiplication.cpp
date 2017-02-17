class Solution {
public:
    // brute force: O(mnp)time, O(mn)space, 17.24%
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), p = A[0].size(), n = B[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < p; k++){
                    if((A[i][k] != 0) && (B[k][j] != 0))
                        ret[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return ret;
    }

    // move up if check: O(mnp)time, O(mn)space, 82.24%, ok
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), p = A[0].size(), n = B[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int k = 0; k < p; k++){
                if(A[i][k] != 0){   // check non-zero here to speed up
                    for(int j = 0; j < n; j++){
                        if(B[k][j] != 0)
                            ret[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return ret;
    }
};
