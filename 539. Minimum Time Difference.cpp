class Solution {
public:
    // brute force: O(N2) time, O(N)space,
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() < 2) return 0;
        int ret = INT_MAX;
        vector<int> time;
        for(auto s: timePoints){
            int h = (s[0] - '0') * 10 + s[1] - '0';
            int m = (s[3] - '0') * 10 + s[4] - '0';
            time.push_back(h * 60 + m);
            // if(h == 0) time.push_back(24 * 60 + m);
        }
        sort(time.begin(), time.end());
        for(int i = 0; i < time.size(); i++){
            for(int j = i + 1; j < time.size(); j++){
                int diff = time[j] - time[i];
                ret = min(ret, min(24* 60 - diff, diff));
            }
        }
        return ret;
    }

    // one pass: O(NlogN) time, O(N)space, ok
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() < 2) return 0;
        int ret = INT_MAX;
        vector<int> time;
        for(auto s: timePoints){
            int h = (s[0] - '0') * 10 + s[1] - '0';
            int m = (s[3] - '0') * 10 + s[4] - '0';
            time.push_back(h * 60 + m);
            time.push_back((24 + h) * 60 + m);
        }
        sort(time.begin(), time.end());
        for(int i = 1; i < time.size(); i++){
            ret = min(ret, time[i] - time[i - 1]);
        }
        return ret;
    }
};
