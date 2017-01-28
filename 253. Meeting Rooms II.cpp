/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct cmp{
    bool operator() (Interval in1, Interval in2){  // overload the compare func for priority queue
        return in1.end >= in2.end;
    }
};

class Solution {
public:
    // sort & naive compare: O(N2), 91.71%, ok
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        vector<Interval> rooms;
        sort(intervals.begin(), intervals.end(), mySort);
        for(int i = 0; i < intervals.size(); i++){
            bool find = false;
            for(int j = 0; j < rooms.size(); j++){
                if(intervals[i].start >= rooms[j].end){
                    find = true;
                    rooms[j] = intervals[i];
                    break;
                }
            }
            if(rooms.empty() || !find)
                rooms.push_back(intervals[i]);
        }
        return rooms.size();
    }

    static bool mySort(Interval in1, Interval in2){
        return in1.start <= in2.start;
    }

    // sort & min heap: O(NlogN), 91.71%, ok
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        priority_queue<Interval, vector<Interval>, cmp> rooms;
        sort(intervals.begin(), intervals.end(), mySort);
        rooms.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start >= rooms.top().end)
                rooms.pop();
            rooms.push(intervals[i]);
        }
        return rooms.size();
    }
};
