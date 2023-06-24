class Solution {
public:
    int longestString(int x, int y, int z) {
         int ans=(min(x,y)*2+z)*2;
        if(x != y)
            ans +=2;
        return ans;
    }
};