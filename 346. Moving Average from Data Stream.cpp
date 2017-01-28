class MovingAverage {
private:
    double sum;
    queue<int> cache;
    int window;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = size;
        sum = 0;
    }
    // queue, O(1), 85.26%, ok
    double next(int val) {
        if(!window) return 0.0;
        cache.push(val);
        sum += val;
        if(cache.size() > window){
            sum -=cache.front();
            cache.pop();
        }
        return sum / cache.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
