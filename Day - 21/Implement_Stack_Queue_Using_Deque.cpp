// T.C -: Push O(1) Pop,Peek O(1) & S.C -: O(N)
class MyStack {
public:
    deque<int>dq;
    MyStack() {}

    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int removed = dq.back();
        dq.pop_back();
        return removed;
    }
    
    int top() {
        return dq.back();
    }
    
    bool empty() {
        return dq.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// T.C -: Push O(N) Pop,Peek O(1) & S.C -: O(N)
class MyQueue {
public:
    deque<int>dq;
    MyQueue() {}

    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int removed = dq.front();
        dq.pop_front();
        return removed;
    }
    
    int top() {
        return dq.front();
    }
    
    bool empty() {
        return dq.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */