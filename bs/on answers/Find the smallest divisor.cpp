class Solution {
public:

  int sumDivision(vector<int> &nums, int mid){
    int sum=0;

    for(int i=0;i<nums.size();i++){
      sum=sum+ceil((double)nums[i]/mid);
    }
    return sum;
  }
  int smallestDivisor(vector<int> &nums, int limit) {
     int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (sumDivision(nums, mid) <= limit) {
                ans=mid;
                end = mid-1;
            } else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};