class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			if((a!=2 && b!=2) || (a==b) ){
                return false;
            }
            return true;
		}
};