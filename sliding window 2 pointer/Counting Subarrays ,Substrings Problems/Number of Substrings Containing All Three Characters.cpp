class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0;
        int left=0,right=0;
        unordered_map<char,int>mp;
        while(right<n){
            mp[s[right]]++;
            while(mp.size()==3){
                count=count+(n-right);
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            right++;
        }

        return count;
    }
};