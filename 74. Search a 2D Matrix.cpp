class Solution {
public:
    // binary search as a 1D sorted array): O(logmn) time, O(1)space, 45.5%, ok
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(!matrix.size() || !matrix[0].size()) return false;    // boundry check
        int row = matrix.size(), column = matrix[0].size();
        int head = 0, tail = row * column - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            int current = matrix[mid / column][mid % column];
            if(current == target) return true;
            else if(current > target) tail = mid - 1;
            else head = mid + 1;
        }
        return false;
    }
};
