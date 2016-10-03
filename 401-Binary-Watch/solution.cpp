class Solution {
public:
    //calculate the number of bits that says one
    int numOfBits(int num){
        int i = 0;
        int count = 0;
        while(i <= 5){
            double temp = pow(2.0, i);
            if(int(temp) & num) count += 1;
            i++;
        }
        return count;
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        unordered_map<int, vector<string> > hour, min;
        int i, j = 0;
        while(i <= 11){
            hour[numOfBits(i)].push_back(to_string(i));
            i++;
        }
        while(j <= 59){
            if(j < 10) min[numOfBits(j)].push_back("0" + to_string(j));
            else min[numOfBits(j)].push_back(to_string(j));
            j++;
        }
        for(int i = 0; i <= num && i <= 3; i++){
            int j = num - i;
            if(j >= 0 && j < 6){
                for(auto h: hour[i])
                    for(auto m : min[j])
                        ans.push_back(h + ":" + m);
            }
        }
        return ans;
    }
};