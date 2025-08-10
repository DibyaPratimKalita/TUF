class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int maxlen = 1;
        int left =0, right =0;
        while(right < n){
            mp[s[right]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            int len = right - left +1;
            maxlen = max(maxlen, len);
            right++;
        }

        return maxlen;
    }
};

/*

a a


*/