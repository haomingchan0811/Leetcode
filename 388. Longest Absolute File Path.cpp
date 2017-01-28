class Solution {
public:
    // hashmap and backtrace: O(N), 38.29%, ok
    int lengthLongestPath(string input) {
        if(input.empty()) return 0;
        unordered_map<int, int> backtrace;
        int currLevel = 0;
        int maxLength = 0;
        int i = 0, length = 0;
        bool isFile = false;
        while(i < input.size()){
            length = 0;
            while(i < input.size() && input[i] != '\n' && input[i] != '\t') {
                if(input[i] == '.') isFile = true;
                length++;
                i++;
            }
            if(i < input.size() && input[i] == '\n'){
                // bug: dash("\") count -> except for the root dir -> + (currLevel > 0)
                backtrace[currLevel] = backtrace[currLevel - 1] + length + (currLevel > 0);
                // bug: an empty dir chain is not a valid path
                if(isFile) maxLength = max(maxLength, backtrace[currLevel]);
                i++;
                isFile = false;
                currLevel = 0; // bug: this line was wrongly put in the below if-loop -> multiple root dir will be wrong
            }
            if(i < input.size() && input[i] == '\t'){
                currLevel++;
                i++;
            }
        }
        if(isFile) maxLength = max(maxLength, backtrace[currLevel - 1] + length + (currLevel > 0));
        return maxLength;
    }
};
