class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
      vector<int> ans;
      for(auto vec: matrix){
        for(auto ele: vec){
          ans.push_back(ele);
        }
      }
      sort(ans.begin(),ans.end());
      return ans[ans.size()/2];
    }
};