class Solution {
   public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        string ans = "";
        for (int i = 0; i < n; i++) {
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            if (temp.size() > 0) {
                ans += ' ' + temp;
            }
        }

        return ans.substr(1);
    }
};