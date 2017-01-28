class Solution {
public:
    // binary search the left & right nearest heaters for every house
    // O(NlogN) or O(MlogN): 95.16%, ok
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(heaters.empty() || houses.empty()) return 0;
        sort(heaters.begin(), heaters.end());
        int ret = 0, dist;
        for(auto h: houses){
            int head = 0, tail = heaters.size() - 1, mid;
            while(head <= tail){    // find the heater that is closest to the house
                mid = head + (tail - head) / 2;
                if(heaters[mid] > h && (mid - 1 >= 0 && heaters[mid - 1] >= h))
                    tail = mid - 1;
                else if(heaters[mid] < h && (mid + 1 < heaters.size() && heaters[mid + 1] <= h))
                    head = mid + 1;
                else break;
            }
            if(heaters[mid] <= h){
                dist = h - heaters[mid];
                if(mid + 1 < heaters.size()) dist = min(dist, heaters[mid + 1] - h);
            }
            else{
                dist = heaters[mid] - h;
                if(mid - 1 >= 0) dist = min(dist, h - heaters[mid - 1]);
            }
            ret = max(ret, dist);
        }
        return ret;
    }

    // sort both arrays and use two pointers: 61.33%, ok
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(heaters.empty() || houses.empty()) return 0;
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int ret = 0;
        int i = 0, j = 0;
        while(i < houses.size()){
            while(j < heaters.size() - 1 && (abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i]))){
                j++;
            }
            ret = max(ret, abs(heaters[j] - houses[i]));
            i++;
        }
        return ret;
    }

    // more elegant with binary search (STL: lower_bound):
    // O(NlogN) or O(MlogN): 60.23%, ok
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(heaters.empty() || houses.empty()) return 0;
        sort(heaters.begin(), heaters.end());
        int ret = 0;
        for(auto h: houses){
            int dist = INT_MAX;
            auto rightNeighbor = lower_bound(heaters.begin(), heaters.end(), h);
            if(rightNeighbor != heaters.end()) dist = *rightNeighbor - h;
            if(rightNeighbor != heaters.begin()){
                auto leftNeighbor = rightNeighbor - 1;
                dist = min(dist, h - *leftNeighbor);
            }
            ret = max(ret, dist);
        }
        return ret;
    }
};
