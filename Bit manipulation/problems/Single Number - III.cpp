class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			vector<int>ans;
            unordered_map<int,int>mp;
            for(int num: nums){
                mp[num]++;
            }
            // note that using set to avoid nlogn time complexity , to n time complexity
            set<int>st;
            for(auto it : mp){
                if(it.second==1){
                    st.insert(it.first);
                }
            }
            
            for(auto it: st){
                ans.push_back(it);
            }

            return ans;
		}
};