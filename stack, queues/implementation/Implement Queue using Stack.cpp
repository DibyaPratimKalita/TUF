class StackQueue {
   public:
    stack<int> s1, s2;
    StackQueue() {}

    void push(int x) {
        while (s1.empty() == false) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.empty() == false) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int k = s1.top();
        s1.pop();
        return k;
    }

    int peek() { return s1.top(); }

    bool isEmpty() {
      return s1.empty();
    }
};