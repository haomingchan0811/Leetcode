class MyQueue {
public:
    // two stacks: 70.18%, use a deputy stack to reverse the order
    stack<int> mainStack, deputy;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        mainStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(deputy.empty()){
            while(mainStack.size()){
                deputy.push(mainStack.top());
                mainStack.pop();
            }
        }
        int target = deputy.top();
        deputy.pop();
        return target;
    }

    /** Get the front element. */
    int peek() {
        if(deputy.empty()) {
            while(mainStack.size()){
                deputy.push(mainStack.top());
                mainStack.pop();
            }
        }
        return deputy.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return mainStack.empty() && deputy.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
