class node {
public:
    int val;
    node* next;
    
    node(int x) {
        val = x;
        next = NULL;
    }
};

class LinkedListStack {
public:
    node *head; // Renamed from 'top' to 'head'
    int size;

    LinkedListStack() {
        head = NULL;
        size = 0;
    }
    
    void push(int x) {
        node *element = new node(x);
        element->next = head;
        head = element;
        size++;
    }
    
    int pop() {
        if (head == NULL) {
            return -1;
        }
        int ans = head->val;
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    
    int top() {  
        if (head == NULL) return -1;
        return head->val;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
};
