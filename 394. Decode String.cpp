class Solution {
public:
    // two stacks: O(N) time & space, 15.34%, ok
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> str;
        string ret = "";
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                int num = s[i++] - '0';
                while(i < s.size() && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                i--;
                cnt.push(num);
            }
            else if(s[i] == '['){
                str.push(ret);  // key
                ret = "";
            }
            else if(s[i] == ']'){
                int num = cnt.top();
                string temp = str.top();
                cnt.pop();
                str.pop();
                while(num--) temp += ret;
                ret = temp;     // key
            }
            else ret += s[i];
        }
        return ret;
    }

    // recursive: O(N) time & space, 15.34%, ok
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    // bug: "int i", should return referrence, o/w hard to trace the index
    string decodeString(string s, int& i) {
        string ret = "";
        while(i < s.size() && s[i] != ']'){
            if(!isdigit(s[i])) ret += s[i++];
            else{
                int num = 0;
                while(i < s.size() && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                i++; // '['
                string str = decodeString(s, i);
                i ++; // ']'
                while(num--) ret += str;
            }
        }
        return ret;
    }
};
