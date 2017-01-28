class Solution {
public:
    // stack: 13ms
    int evalRPN(vector<string>& tokens) {
        stack<int> cache;
        for(int i = 0; i < tokens.size(); i++){
            string cur = tokens[i];
            if(cur == "+" || cur == "-" || cur == "*" || cur == "/"){
                int y = cache.top();
                cache.pop();
                int x = cache.top();
                cache.pop();
                cache.push(compute(cur[0], x, y));
            }
            else cache.push(stoi(cur));
        }
        return cache.top();
    }

    int compute(char symbol, int x, int y){
        switch(symbol){
            case '*': return x * y; break;
            case '+': return x + y; break;
            case '-': return x - y; break;
            case '/': return x / y; break;
        }
        return 0;
    }
};
