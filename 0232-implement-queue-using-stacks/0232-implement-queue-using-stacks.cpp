class MyQueue {
    private:
    vector<int> xyz;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        xyz.push_back(x);
    }
    
    int pop() {
        int d = xyz[0];
        xyz.erase(xyz.begin());
        return d;
    }
    
    int peek() {
        return xyz[0];
    }
    
    bool empty() {
        return xyz.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */