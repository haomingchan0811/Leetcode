class Solution {
public:
    // brute force starting from sqrtRoot: O(sqrt(N))time, O(1)space, 37.61%, ok
    vector<int> constructRectangle(int area) {
        vector<int> ret;
        if(area <= 0) return ret;
        for(int w = sqrt(area); w > 0; w--){
            int l = area / w;
            if(w * l == area){
                ret = {l, w};
                return ret;
            }
        }
        return ret;
    }

    // brute force optimize: O(sqrt(N))time, no space, 37.61%, ok
    vector<int> constructRectangle(int area) {
        vector<int> ret;
        if(area <= 0) return ret;
        for(int w = sqrt(area); w > 0; w--){
            if(area % w == 0){
                ret = {area / w, w};
                return ret;
            }
        }
        return ret;
    }
};
