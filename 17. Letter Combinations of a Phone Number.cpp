class Solution {
private:
    vector<vector<string>> mapping = {{}, {}, {"a","b","c"}, {"d","e","f"}, {"g","h","i"},
                        {"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
public:
    // recursive: O(N), 28.32%, ok
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        vector<string> remain(1, "");
        if(digits.empty()) return ret;
        int i = digits[0] - '0';
        if(digits.size() > 1){
            string sub = digits.substr(1);
            remain = letterCombinations(sub);
        }
        for(auto letter: mapping[i]){
            for(auto r: remain){
                ret.push_back(letter + r);
            }
        }
        return ret;
    }

    // iterative: 1.99%, 3ms
    vector<string> letterCombinations(string digits){
        vector<string> ret;
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // cleverer repr
        if(!digits.size()) return ret;
        ret.push_back("");  // keypoint: initialize when digits is not null
        for(int i = 0; i < digits.size(); i++){
            string candidate = map[digits[i] - '0'];
            vector<string> temp;
            for(int j = 0; j < candidate.size(); j++){
                for(int k = 0; k < ret.size(); k++){
                    temp.push_back(ret[k] + candidate[j]);
                }
            }
            ret = temp;
        }
        return ret;
    }
};
