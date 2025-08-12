class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int minIndex=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[minIndex]){
                    minIndex=j;
                }
            }

            if(minIndex!=i){
                swap(nums[i],nums[minIndex]);
            }
        }
        return nums;
    }
};
