class Solution {
   public:
    int longestNonRepeatingSubstring(string& s) {
        int left = 0, right = 0;
        unordered_set<int> st;
        int ans = 0;
        while (right < s.size()) {
            if (st.count(s[right]) == 0) {
                st.insert(s[right]);
                ans = max(ans, right - left + 1);
                right++;
            } else {
                st.erase(s[left]);
                left++;
            }
        }

        return ans;
    }
};