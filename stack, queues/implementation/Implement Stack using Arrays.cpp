class ArrayStack {
public:
    int arr[100];
    int t=-1;
    ArrayStack() {
    }
    
    void push(int x) {
        t+=1;
        arr[t]=x;
    }
    
    int pop() {
        int ans=arr[t];
        t-=1;
        return ans;
    }
    
    int top() {
        return arr[t];
    }
    
    bool isEmpty() {
        if(t==-1){
            return true;
        }

        return false;
    }
};