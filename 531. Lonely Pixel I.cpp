class Solution {
public:
    // // brute force with marker: O(mn)time & space, bad
    // int findLonelyPixel(vector<vector<char>>& picture) {
    //     int m = picture.size(), ret = 0;
    //     if(!m) return 0;
    //     int n = picture[0].size();
    //     vector<int> rows(m, 0);
    //     vector<int> cols(n, 0);
    //     vector<vector<int>> flag(m, vector<int>(n, 0));
    //     for(int i = 0; i < m; i++){
    //         for(int j = 0; j < n; j++){
    //             if(flag[i][j]) continue;
    //             flag[i][j] = 1;
    //             if(picture[i][j] == 'B'){
    //                 if(!rows[i] && !cols[j]){
    //                     rows[i] = 1;
    //                     cols[j] = 1;
    //                     int valid = 1;
    //                     for(int i2 = i + 1; i2 < m; i2++){
    //                         flag[i2][j] = 1;
    //                         if(picture[i2][j] == 'B'){
    //                             rows[i2] = 1;
    //                             valid = 0;
    //                         }
    //                     }
    //                     for(int j2 = j + 1; j2 < n; j2++){
    //                         flag[i][j2] = 1;
    //                         if(picture[i][j2] == 'B'){
    //                             cols[j2] = 1;
    //                             valid = 0;
    //                         }
    //                     }
    //                     ret += valid;
    //                 }
    //                 else {
    //                     rows[i] = 1;
    //                     cols[j] = 1;
    //                 }
    //             }
    //         }
    //     }
    //     return ret;
    // }

    // vector markers: O(mn)time, O(m+n)space, ok
    int findLonelyPixel(vector<vector<char>>& picture) {
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
                if(picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1)
                    ret++;
            }
        }
        return ret;
    }
};
