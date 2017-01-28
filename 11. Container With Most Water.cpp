class Solution {
public:
    // Brute force: O(N2), TLE even after optimization
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            // find the rightmost line that's higher than height[i], save calculation
            int higherIndex = 0;
            // for those lower than height[i], we have no choice but to compare the area everytime
            for(int j = i + 1; j < height.size(); j++){
                // if(ans < (j - i) * min(height[i], height[j])) ans = (j - i) * min(height[i], height[j]); // TLE
                if(height[i] <= height[j]) higherIndex = j;
                else ans = max(ans, (j - i) * height[j]);
            }
            ans = max(ans, (higherIndex - i) * height[i]);
        }
        return ans;
    }

    /* Start with the widest container(using the first and the last line). All other narrower containers should be higher to hold more water.
    Thus, after evaluating that widest container, skip lines at both ends that don't support a higher height.
    Then evaluate that new container we arrived at. Repeat until there are no more possible containers left.*/

    // two pointers, O(N): 73.93%, ok
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while(i < j){
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return ans;
    }
};
