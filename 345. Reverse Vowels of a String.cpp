class Solution {
public:
    // Two pointers: O(N)time, O(1)space, 82.60%, ok
    string reverseVowels(string s) {
        if(s.empty()) return s;
        // set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        string vowels = "AEIOUaeiou";  // more elegant
        int head = 0, tail = s.size() - 1;
        while(head < tail){
            // while(head < tail && !vowels.count(s[head])) head++; // for set
            // while(head < tail && !vowels.count(s[tail])) tail--;
            while(head < tail && vowels.find(s[head]) == string::npos) head++; // for string
            while(head < tail && vowels.find(s[tail]) == string::npos) tail--;
            swap(s[head], s[tail]);
            head++; tail--;  // bug: should update or stuck in loop
        }
        return s;
    }
};
