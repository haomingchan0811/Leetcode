class Solution {
public:
    // brute force: O(n2logn2), 54.85%
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return -1;
        vector<int> flatten(matrix[0].begin(), matrix[0].end());
        for(int i = 1; i < matrix.size(); i++)
            flatten.insert(flatten.end(), matrix[i].begin(), matrix[i].end());
        sort(flatten.begin(), flatten.end());
        return flatten[k - 1];
    }

    // binary search: O(nlogn*logn2), 78.97%, ok
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return -1;
        int n = matrix.size();
        int head = matrix[0][0], tail = matrix[n - 1][n - 1];
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            int cnt = 0;
            for(int i = 0; i < n; i++)
                // how many elements are equal or smaller than the target in each row
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if(cnt >= k) tail = mid - 1;
            else head = mid + 1;

        }
        return head;
    }
};
