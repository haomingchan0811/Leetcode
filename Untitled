class MyStack {
public:
    // two queues, always has one empty queue to reverse order
        push O(1), pop O(n), 69.74%, ok
    queue<int> q1, q2;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if(q1.size()) q1.push(x);
        else q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q2.empty()) swap(q1, q2);
        while(q2.size() > 1){
            q1.push(q2.front());
            q2.pop();
        }
        int ans = q2.front();
        q2.pop();
        return ans;
    }

    /** Get the top element. */
    int top() {
        if(q2.empty()) return q1.back();
        else return q2.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

class MyStack {
public:
    // one queue, always reverse when new num inserts
    // push O(n), pop O(1), 69.74%, ok
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int size = q.size();
        q.push(x);
        while(size--){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
       int ans = q.front();
       q.pop();
       return ans;
    }

    /** Get the top element. */
    int top() {
       return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
