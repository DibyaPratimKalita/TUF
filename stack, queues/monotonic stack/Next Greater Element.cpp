class Solution {
   public:
    vector<int> nextLargerElement(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,-1);
        for (int i = 0; i < n; i++) {
            while (st.empty() == false && arr[i] > arr[st.top()]) {
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
