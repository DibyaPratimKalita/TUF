class Solution {
  public:
    int LongestBitonicSequence(vector<int> nums) {
         int n = nums.size();
        vector<int> LISdp(n,1);
        vector<int> LDSdp(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                //which is the LIS till position i
                if(nums[j] < nums[i]){
                    LISdp[i]=max(LISdp[i],LISdp[j] + 1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                //LIS from rightside to leftside
                if(nums[j] < nums[i]){
                    LDSdp[i]=max(LDSdp[i],LDSdp[j] + 1);
                }
            }
        }
        int maxiBitonic=1;
        for(int i=0;i<n;i++){
            maxiBitonic=max(maxiBitonic, LISdp[i] + LDSdp[i] -1);
        }

        return maxiBitonic;
    }
};
