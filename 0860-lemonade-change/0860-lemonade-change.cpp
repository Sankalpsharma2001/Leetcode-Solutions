class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int m5=0,m10=0,m20=0;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                m5++;
            }
            else if(bills[i]==10)
            {
                m10++;
                if(m5>0)
                    m5--;
                else
                    return false;
            }
            else
            {
                m20++;
                if(m10>0 && m5>0)
                {
                    m10--;
                    m5--;
                }
                else if(m5>2)
                {
                    m5-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};