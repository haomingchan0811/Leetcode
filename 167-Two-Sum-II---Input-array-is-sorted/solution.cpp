class Solution {
public:
    // hashtable
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> add;    // store the complement of the member
        vector<int> ret;
        int len = numbers.size();
        bool found = false;
        for(int i = 0; i < len && (!found); i ++){
            int imp = target - numbers[i];
            unordered_map<int, int>::iterator it = add.begin();
            while(it != add.end()){
                if(it->first == numbers[i]){
                    ret.push_back(it->second);
                    ret.push_back(i + 1);
                    found = true;
                    break;
                }
                it ++;
            }
            add[imp] = i + 1;
        }
        return ret;
    }
};