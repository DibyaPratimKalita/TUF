class Solution {
   public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int count = 0;
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr=(xorr ^ nums[i]);
            int remXorr=(xorr ^ k);
            if(mp.find(remXorr)!=mp.end()){
                count+=mp[remXorr];
            }
            mp[xorr]++;
        }
        return count;
    }
};