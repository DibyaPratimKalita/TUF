class ArrayQueue {
public:
    int arr[100];
    int f, b;

    ArrayQueue() {
        f = -1;
        b = -1;
    }
    
    void push(int x) {
        if (b == 99) { // Prevent overflow
            throw std::overflow_error("Queue overflow");
        }
        if (f == -1 && b == -1) { // First element
            f = 0;
            b = 0;
        } else {
            b++;
        }
        arr[b] = x;
    }
    
    int pop() {
        if (isEmpty()) { // Prevent underflow
            throw std::underflow_error("Queue underflow");
        }
        int ans = arr[f];
        f++;
        if (f > b) { // Reset queue when empty
            f = -1;
            b = -1;
        }
        return ans;
    }
    
    int peek() {
        if (isEmpty()) { // Prevent access to empty queue
            throw std::runtime_error("Queue is empty");
        }
        return arr[f];
    }
    
    bool isEmpty() {
        return (f == -1 || f > b);
    }
};
