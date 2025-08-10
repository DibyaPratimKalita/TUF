class Solution {
public:
    long long count = 0;
    void merge(vector<int> &nums, int start, int mid, int end){
        int left = start, right = mid + 1;
        vector<int>temp;

        while(left <= mid && right <=end){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                count += (mid - left +1);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= end){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = 0; i < temp.size(); i++){
            nums[start + i] = temp[i];
        }

    }
    void divide(vector<int> &nums, int start, int end){
        if(start == end){
            return;
        }
        int mid = start + (end-start)/2;

        divide(nums, start, mid);
        divide(nums, mid+1, end);

        merge(nums, start, mid, end);
    }
    
   long long int numberOfInversions(vector<int> nums) {
        divide(nums, 0 , nums.size()-1);
        return count;
    }
};