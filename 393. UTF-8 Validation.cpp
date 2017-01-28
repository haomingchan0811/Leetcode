class Solution {
public:
    // brute force: O(N)time, O(1)space, 8.63%, ok
    bool validUtf8(vector<int>& data) {
        if(data.empty()) return false;
        for(int i = 0; i < data.size(); i++){
            bitset<32> curr(data[i]);
            int bytes = 0, j = 7;
            while(j && curr[j]) {bytes++; j--;}
            if(bytes == 1 || bytes > 4) return false;
            while(bytes-- > 1){
                i++;
                if(i == data.size()) return false;
                bitset<32> child(data[i]);
                if(!(child[7] == 1 && child[6] == 0)) return false;
            }
        }
        return true;
    }
}; 
