class Solution {
public:
    bool isPowerOfTwo(int n) {
      
       int x=n;
        
        if(x<=0) return false;
        return (x&(x-1))==0;
    }
};