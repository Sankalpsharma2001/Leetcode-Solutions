class Solution {
public:
    int lastRemaining(int n) {
        bool left=true;
        int head=1,step=1,remain=n;
        while(remain>1)
        {
            if(left || remain&1)
            {
                head=head+step;
            }
            step*=2;
            left=!left;
            remain/=2;
        }
        return head;
    }
};