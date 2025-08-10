class Solution {
   public:
    void solve(int ind, string temp, vector<string>& ans, string digits,unordered_map<int, string>& mp) {
        if (ind == digits.size()) {
            ans.push_back(temp);
        }

        int digit = digits[ind] - '0';

        for (int i = 0; i < mp[digit].size(); i++) {
            temp += mp[digit][i];
            solve(ind + 1, temp, ans, digits,mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> ans;
        string temp = "";
        solve(0, temp, ans, digits,mp);

        return ans;
    }
};