class Solution {
public:
    // // dp: O(N2), 56.93%, ok
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> ret;
    //     if(!numRows) return ret;
    //     ret.push_back(vector<int>(1, 1));
    //     if(numRows == 1) return ret;
    //     ret.push_back(vector<int>(2, 1));
    //     if(numRows == 2) return ret;
    //     for(int i = 3; i <= numRows; i++){
    //         vector<int> temp;
    //         for(int j = 1; j <= i; j++){
    //             if(j == 1 || j == i) temp.push_back(1);
    //             else temp.push_back(ret[i - 2][j - 2] + ret[i - 2][j - 1]);
    //         }
    //         ret.push_back(temp);
    //     }
    //     return ret;
    // }

    // more elegant: O(N2), 56.93%, ok
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i = 0; i < numRows; i++){
            ret.push_back(vector<int>(i + 1, 1));
            for(int j = 1; j < i; j++)
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        return ret;
    }
};
