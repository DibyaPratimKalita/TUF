class Solution {
   public:
    vector<int> stockSpan(vector<int> arr, int n) {
        
        stack<int>st;
        vector<int> ans(n,1);
        for (int i = n - 1; i >= 0; i--) {
            while(st.empty()==false && arr[i]>arr[st.top()]){
                ans[st.top()]=st.top()-i;
                st.pop();
            }
            st.push(i);
        }
        //for the case - [60,70,80]=> [1,1,1]
        //but it should be =>[1,2,3]
        while(st.empty()==false){
            ans[st.top()]=st.top()+1;
            st.pop();
        }
        return ans;
    }
};
