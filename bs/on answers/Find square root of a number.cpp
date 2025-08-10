class Solution {
public:
double solve(double x, int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            return solve(1 / x, -n);
        if (n % 2 == 0)
            return solve(x * x, n / 2);
        else
            return x * solve(x * x, (n - 1) / 2);
    }
  
  int NthRoot(int N, int M) {
       int start=1,end=M;

       while(start<=end){
          int mid=start+(end-start)/2;

          double midN=solve(mid,N);

          if(midN==M){
            return mid;
          } 
          else if(midN>M){
            end=mid-1;
          }
          else {
            start=mid+1;
          }
       }
       
       return -1;
    }
  };
