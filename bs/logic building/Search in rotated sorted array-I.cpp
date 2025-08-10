class Solution {
public:
    int search(vector<int> &nums, int target) {
       int start=0,end=nums.size()-1;
       int start1,end1;

       while(start<=end)
       {
            int mid=start+(end-start)/2;

            if (nums[mid] == target) {
                return mid;
            }


            //left part sorted
            if(nums[start]<=nums[mid]){
                //search left of left part
                if(nums[start]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                //search right of left part
                else{
                    start=mid+1;
                }
            }
            //search in right sorted
            else{
                if(nums[mid]<target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }

            
       }
       return -1;
    }
};