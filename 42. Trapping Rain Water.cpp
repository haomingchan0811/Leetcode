class Solution {
public:
    // brute force (two pointers): min(maxHeightFromLeft, maxHeightFromRight) - self
    // O(N^2) time, O(1)space, 0.18%
    int trap(vector<int>& height) {
        int ret = 0;
        if(height.empty()) return ret;
        for(int i = 1; i < height.size() - 1; i++){  // exclude the head and tail
            int maxLeftH = -1, maxRightH = -1;
            for(int j = 0; j < height.size(); j++){
                if(j <= i) maxLeftH = max(maxLeftH, height[j]);
                if(j >= i) maxRightH = max(maxRightH, height[j]);
            }
            ret += min(maxLeftH, maxRightH) - height[i];
        }
        return ret;
    }

    // dp: maxLeftH[i] = max(maxLeftH[i - 1], height[i]), same for maxRightH
    // O(N) time & space, 29.64%, ok
    int trap(vector<int>& height) {
        int ret = 0, size = height.size();
        if(!size) return ret;
        vector<int> maxLeftH(size, height[0]);
        vector<int> maxRightH(size, height[size - 1]);

        for(int i = 1; i < size; i++)
            maxLeftH[i] = max(maxLeftH[i - 1], height[i]);
        for(int i = size - 2; i >= 0; i--)
            maxRightH[i] = max(maxRightH[i + 1], height[i]);

        for(int i = 1; i < size; i++)    // exclude the head and tail
            ret += min(maxLeftH[i], maxRightH[i]) - height[i];

        return ret;
    }

    // stack???
};s
