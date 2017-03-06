class Solution {
public:
    // // dp precompute + brute force: O(mn)time & space, bad
    // int findBlackPixel(vector<vector<char>>& picture, int N) {
    //     int m = picture.size(), n = picture[0].size();
    //     int ret = 0;
    //     vector<vector<int>> left(m, vector<int>(n, 0));
    //     vector<vector<int>> right(m, vector<int>(n, 0));
    //     vector<vector<int>> up(m, vector<int>(n, 0));
    //     vector<vector<int>> down(m, vector<int>(n, 0));
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //           if(j == 0) left[i][j] = (picture[i][j] == 'B');
    //           else left[i][j] = left[i][j - 1] + (picture[i][j] == 'B');
    //         }
    //     }

    //     for(int i = 0; i < m; i++){
    //         for(int j = n - 1; j >= 0; j--){
    //             if(j == n - 1) right[i][j] = (picture[i][j] == 'B');
    //             else right[i][j] = right[i][j + 1] + (picture[i][j] == 'B');
    //         }
    //     }

    //     for(int j = 0; j < n; j++){
    //         for(int i = 0; i < m; i++){
    //           if(i == 0) down[i][j] = (picture[i][j] == 'B');
    //           else down[i][j] = down[i - 1][j] + (picture[i][j] == 'B');
    //         }
    //     }

    //     for(int j = 0; j < n; j++){
    //         for(int i = m - 1; i >= 0; i--){
    //           if(i == m - 1) up[i][j] = (picture[i][j] == 'B');
    //           else up[i][j] = up[i + 1][j] + (picture[i][j] == 'B');
    //         }
    //     }

    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //             if((left[i][j] + right[i][j] - 1 == N) && (up[i][j] + down[i][j] - 1 == N)){
    //                 int valid = 1;
    //                 for(int k = 0; k < m; k++){
    //                     if(picture[k][j] == 'B'){
    //                         if(picture[k] != picture[i]){
    //                             valid = 0;
    //                             break;
    //                         }
    //                     }
    //                 }
    //                 ret += valid;
    //             }
    //         }
    //     }
    //     return ret;
    // }

    // vector marker: O(mn)time, O(m+n)space, 50%, ok
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size(), n = picture[0].size();
        int ret = 0;
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
               if(picture[i][j] == 'B'){
                   rows[i]++; cols[j]++;
               }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(picture[i][j] == 'B' && rows[i] == N && cols[j] == N){
                    bool valid = true;
                    for(int k = 0; k < m; k++){
                        if(picture[k][j] == 'B' && picture[k] != picture[i]){
                            valid = false; break;
                        }
                    }
                    ret += valid;
                }
            }
        }
        return ret;
    }
};
