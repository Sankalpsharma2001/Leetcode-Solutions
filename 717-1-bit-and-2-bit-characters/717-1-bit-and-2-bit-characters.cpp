class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1)
            return true;
        int c=0,n=bits.size();
        if(bits[n-2]==0)
            return true;
        for(int i=n-2;i>=0 and bits[i];i--)
        {
            if(bits[i]==1)
                c++;
        }
        if(c%2)
            return false;
        return true;
    }
};