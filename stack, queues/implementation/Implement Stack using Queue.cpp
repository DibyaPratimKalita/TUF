class QueueStack {
public:
    queue<int>q;
    QueueStack() {
    }
    
    void push(int x) {
        q.push(x);
        int size=q.size();
        // Rotate elements to maintain stack order
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans= q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
};