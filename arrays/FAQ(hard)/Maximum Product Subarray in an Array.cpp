class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int prod = 1;       

        //from front find maxi
        for(int i =0;i< n;i++){
            if(prod == 0){
                prod = 1;
            }
            prod = prod * nums[i];
            maxi = max(maxi, prod);
        }

        //from back find maxi
        prod =1 ;
        for(int i =n-1;i>=0 ;i--){
            if(prod == 0){
                prod = 1;
            }
            prod = prod * nums[i];
            maxi = max(maxi, prod);
        }
        return maxi;
    }
};