class Solution {
public:
    // check lowerer left diagnol matrix: O(N2)time, space,
    bool validWordSquare(vector<string>& words) {
        if(words.empty()) return true;
        for(int i = 0; i < words.size(); i++){
            string horizontal = words[i];
            if(horizontal.size() > words.size())  // bug: corner case
                return false;
            for(int j = 0; j < horizontal.size(); j++){
                if(words[j].size() <= i || horizontal[j] != words[j][i])
                    return false;
            }
        }
        return true;
    }
};
