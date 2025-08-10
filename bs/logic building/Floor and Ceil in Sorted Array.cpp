class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor=-1, ceil=-1;
        int start=0,end=nums.size()-1;
        vector<int>ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<=x){
                floor=nums[mid];
                start=mid+1;
            }
            else end=mid-1;
        }
        ans.push_back(floor);
        start=0,end=nums.size()-1;

         while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]>=x){
                ceil=nums[mid];
                end=mid-1;
            }
            else start=mid+1;

        }
        ans.push_back(ceil);

        return ans;
    }
};