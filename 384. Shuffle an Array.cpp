class Solution {
private:
    vector<int> original, num;
public:
    Solution(vector<int> nums) {
        original = num = nums;
        srand(time(NULL));  // initialize random seed
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        num = original;
        return num;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < num.size(); i++){
            int j = rand() % num.size();
            swap(num[i], num[j]);
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
