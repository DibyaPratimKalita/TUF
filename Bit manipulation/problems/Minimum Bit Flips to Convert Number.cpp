class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        int difference = start ^ goal;
        int i=0;
        int ans=0;
        while(difference!=0){
            if( difference & 1 == 1 ){
                ans++;
            }
            difference = difference >> 1;
        }

        return ans;
    }
};