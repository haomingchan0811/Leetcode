/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // sort and search: O(NlogN)
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), mySort);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }

    static bool mySort(Interval in1, Interval in2){
        return in1.start <= in2.start;
    }
};
