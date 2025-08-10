/*
  i  
 [0, 0, 1, 1, 2]
        j     k

*/

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        //i -> 0
        //j -> 1
        //k -> 2
        int n = nums.size();
        int i=0,j=0,k= n-1;

        while(j <= k){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k--;
            }
            else{ // j == 0
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }

    }
};