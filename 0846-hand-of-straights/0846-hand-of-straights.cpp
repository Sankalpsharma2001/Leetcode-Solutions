class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize) return false;
       map<int,int> m;
        for(auto &it:hand)
        {
            m[it]++;
        }
        
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++)
        {
            if(m[hand[i]]==0) continue;
            for(int j=0;j<groupSize;j++)
            {
                int find=hand[i]+j;
                if(m[find]==0) return false;
                m[find]--;
            }
            
            
        }
        return true;
        
        
    }
};