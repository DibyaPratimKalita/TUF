struct node {
    int val;
    node *next;
    node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
public:
    node* start, *end;  // Fixed: both are pointers
    int size;
    
    LinkedListQueue() {
        start = end = NULL;
        size = 0;
    }
    
    void push(int x) {
        node *temp = new node(x);
        if(start == NULL) {
            start = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        size++;
    }
    
    int pop() {
        if(isEmpty()) {
            // Handle empty queue case
            return -1; // Or throw an exception
        }
        int ans = start->val;
        node *temp = start;
        start = start->next;
        if(start == NULL) {
            end = NULL; // If queue becomes empty
        }
        delete temp; // Free memory
        size--;
        return ans;
    }
    
    int peek() {
        if(isEmpty()) {
            // Handle empty queue case
            return -1; // Or throw an exception
        }
        return start->val;
    }
    
    bool isEmpty() {
        return (size == 0);  // Fixed: added semicolon
    }
};
