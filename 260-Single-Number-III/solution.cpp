class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int inter = nums[0];    // pointer 
        int count = 1;
        int ansCount = 0;
        for(int i = 1; (i < nums.size()) && (ansCount != 2); i ++){
            count ++;
            if(!(count % 2) && (inter != nums[i])){
                ans.push_back(inter);
                ansCount += 1;
                inter = nums[i];
                count = 1;
                cout << i << " " << count << " " << nums[i] << endl;
            }
            else{
                i += 1;
                count += 1;
                inter = nums[i];
                cout << "-" << i << " " << count << " " << nums[i] << endl;
            }
        }
        if(ansCount == 1) ans.push_back(inter);
        return ans;
    }
};