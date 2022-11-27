class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
       vector<int> a(52,0);
        for(auto &it:ranges)
        {
            a[it[0]]+=1;
            a[it[1]+1]-=1;
            
        }
        for(int i=0;i<51;i++)
        {
            a[i+1]+=a[i];
        }
        for(int i=left;i<=right;i++)
        {
            if(a[i]==0)
                return false;
        }
        return true;
    }
};