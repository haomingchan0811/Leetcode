class Solution {
public:
    // O(N) time and space: 64.24%, ok
    string convert(string s, int numRows) {
        int i = 0, size = s.size();
        string ans = "";
        string level[numRows] = {""};
        while(i < size){
            // bug: inner boundry check "i < size" or invalid char like "\x00" will show up
            for(int j = 0; j < numRows && i < size; j++)
                level[j] += s[i++];
            for(int j = 2; j < numRows && i < size; j++)
                level[numRows - j] += s[i++];
        }
        for(int j = 0; j < numRows; j++)
            ans += level[j];
        return ans;
    }

    // O(N) time and space with more elegancy: 64.24%, ok
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1) return s; // corner case
        string level[numRows] = {""};
        int i = 0, size = s.size();
        int row = 0, step = 1;  // using step to control the index of row
        while(i < size){
            if(row == 0) step = 1;
            if(row == numRows - 1) step = -1;
            level[row] += s[i++];
            row += step;
        }
        for(int j = 0; j < numRows; j++)
            ans += level[j];
        return ans;
    }
};
