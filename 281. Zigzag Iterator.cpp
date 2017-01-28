class ZigzagIterator {
private:
    // Queue: store the iterator of each vector, can be generalized to k vectors, 38.46%, ok
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto itBegin = q.front().first;
        auto itEnd = q.front().second;
        q.pop();
        if(itBegin + 1 != itEnd)
            q.push(make_pair(itBegin + 1, itEnd));
        return *itBegin;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
