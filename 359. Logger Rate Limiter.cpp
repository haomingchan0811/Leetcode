class Logger {
private:
    unordered_map<string, int> time;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    // 52.40%
    bool shouldPrintMessage(int timestamp, string message) {
        if(!time.count(message) || (time.count(message) && (timestamp - time[message] >= 10))){
            time[message] = timestamp;
            return true;
        }
        return false;
    }

    // more elegant: 95.95%, ok
    bool shouldPrintMessage(int timestamp, string message) {
        if(timestamp < time[message])
            return false;
        time[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
