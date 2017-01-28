class Solution {
public:
    // stack: O(N), 0.29%, ok
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> cache;
        unordered_map<char, char> p = {{']', '['}, {')', '('}, {'}', '{'}};
        for(auto c: s){
            if(cache.empty() || c == '[' || c == '(' || c == '{')
                cache.push(c);
            else{
                if(cache.empty() || p[c] != cache.top()) return false;
                cache.pop();
            }
        }
        return cache.empty();
    }
};
