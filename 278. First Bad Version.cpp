// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // binary search, O(logN)time, O(1)space, 40.01%, ok
    int firstBadVersion(int n) {
        int head = 0, tail = n, ret = 0;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(isBadVersion(mid)){
                ret = mid;
                tail = mid - 1;
            }
            else head = mid + 1;
        }
        return ret;
    }
};
