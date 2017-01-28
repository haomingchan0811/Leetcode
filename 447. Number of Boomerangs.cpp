class Solution {
public:
    // O(N2)time, O(N)space: 14.38%
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> flag;
            for(int j = 0; j < points.size(); j++){
                double dist = hypot((points[i].first - points[j].first), (points[i].second - points[j].second));
                ret += 2 * flag[dist];
                flag[dist]++;
            }
        }
        return ret;
    }
};
