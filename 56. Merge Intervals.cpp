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
    bool operator() (Interval a, Interval b){
        return a.start > b.start || (a.start == b.start && a.end > b.end);
    }
};

class Solution {
public:
    // priority queue: O(NlogN)time & space, 68.53%, ok
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.empty()) return ret;
        priority_queue<Interval, vector<Interval>, cmp> pq;
        for(auto i: intervals) pq.push(i);

        int head = pq.top().start, tail = pq.top().end;
        pq.pop();
        while(pq.size()){
            int h = pq.top().start, t = pq.top().end;
            pq.pop();
            // bug: tail may be greater than t
            if(h <= tail) tail = max(t, tail);
            else{
                ret.push_back(Interval(head, tail));
                head = h, tail = t;
            }
        }
        ret.push_back(Interval(head, tail));
        return ret;
    }

    // sort with lambda: O(NlogN)time & space, 84.42%, ok
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.empty()) return ret;
        // learn lambda !!!!
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        int head = intervals[0].start, tail = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            int s = intervals[i].start, e = intervals[i].end;
            // bug: tail may be greater than t
            if(s <= tail) tail = max(e, tail);
            else{
                ret.push_back(Interval(head, tail));
                head = s, tail = e;
            }
        }
        ret.push_back(Interval(head, tail));
        return ret;
    }
};
