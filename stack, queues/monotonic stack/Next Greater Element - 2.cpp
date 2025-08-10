class Solution {
   public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2*n; i++) {
            while (st.empty() == false && nums[st.top()] < nums[i % n]) {
                int top = st.top();
                st.pop();

                ans[top] = nums[i % n];
            }
            st.push(i % n);
        }

        return ans;
    }
};