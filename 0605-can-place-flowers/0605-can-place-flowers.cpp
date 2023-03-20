class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       if(n==0) return true;
        if(flowerbed.size()==1)
        {
            return flowerbed[0]==0;
        }
        for(int i=0;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i]==0 && flowerbed[i+1]==0 && (i==0 || flowerbed[i-1]==0))
            {
                flowerbed[i]=1;
                n--;
            }
        }
        if( flowerbed[flowerbed.size()-1]==0 &&  flowerbed[flowerbed.size()-2]==0) n--;
        return n<=0;
    }
};