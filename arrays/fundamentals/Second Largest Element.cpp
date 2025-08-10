class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
      int n=nums.size();
      int maxi=nums[0], secondMaxi=-1;

      for(int i=0;i<n;i++){
        if(nums[i]>maxi){
            secondMaxi=maxi;
            maxi=nums[i];
        }else if(nums[i]<maxi && nums[i]>secondMaxi){
            secondMaxi=nums[i];
        }
      }

      return secondMaxi;
    }
};