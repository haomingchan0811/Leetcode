class Solution {
public:
    // hash table: O(mn)time, O(1)space, 1.85%
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        if(words.empty()) return ret;
        unordered_map<int, string> mapping
            = {{1, "qwertyuiop"}, {2, "asdfghjkl"}, {3, "zxcvbnm"}};

        for(int i = 0; i < words.size(); i++){
            int tag;
            if(!words[i].empty()){
                for(auto m: mapping){
                    if(m.second.find(tolower(words[i][0])) != string::npos){
                        tag = m.first;
                        break;
                    }
                }
            }
            bool isValid = true;
            for(int j = 1; j < words[i].size(); j++){
                string s = mapping[tag];
                if(s.find(tolower(words[i][j])) == string::npos){
                    isValid = false;
                    break;
                }
            }
            if(isValid) ret.push_back(words[i]);
        }
        return ret;
    }

    // regular expression
    vector<string> findWords(vector<string>& words) {

    }

};
