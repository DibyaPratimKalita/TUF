class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int n=nums.size();
        int store=nums[0];
        for(int i=0;i<n;i++){
            nums[i]=nums[i+1];
        }
        nums[n-1]=store;
    }
};