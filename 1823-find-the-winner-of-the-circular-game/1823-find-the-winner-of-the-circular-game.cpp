class Solution {
public:
    void josephus(vector<int> &s,int i,int k)
    {
        if(s.size()==1)
        {
            return; 
        }
      
        i+=k;
        i%=s.size();
        s.erase(s.begin()+i);
        josephus(s,i,k);
    }
    int findTheWinner(int n, int k) {
        vector<int> s(n);
        for(int i=0;i<n;i++)
        {
            s[i]=(i+1);
        }
        --k;
         josephus(s,0,k);
        return s[0];
    }
};