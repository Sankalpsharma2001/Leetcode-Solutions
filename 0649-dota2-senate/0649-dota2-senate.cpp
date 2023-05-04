class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> qr,qd;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')
                qr.push(i);
            else 
                qd.push(i);
        }
        while(!qr.empty() && !qd.empty())
        {
            int ridx=qr.front();
            int didx=qd.front();
            qr.pop();
            qd.pop();
            if(ridx<didx)
            {
                qr.push(ridx+n);
            }
            else
                qd.push(didx+n);
        }
        return qr.size()>qd.size()?"Radiant":"Dire";
    }
};