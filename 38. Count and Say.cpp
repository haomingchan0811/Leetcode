class Solution {
public:
    // overflow easily using addition, use string instead : 3ms
    // O(N^2)? as the length of k-th string is a least k, 28.66%, ok
    string countAndSay(int n) {
        string curr = "1";
        while(--n){
            string temp = "";
            for(int j = 0; j < curr.size(); j++){
                int count = 1;
                while(j < curr.size() && curr[j] == curr[j+1]) {j++; count++;}
                temp += to_string(count) + curr[j];
            }
            curr = temp;
        }
        return curr;
    }
};
