//CHECK notes
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        //prefix sum to index
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0;
        int maxlen=0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                int len=i-mp[rem];
                maxlen=max(maxlen,len);
            }
            
            //here need to do a check for 
            // because we need the longest 
            //hence most left ended i only
            //unlike in case of count
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            
        }
        return maxlen;
    }
};
