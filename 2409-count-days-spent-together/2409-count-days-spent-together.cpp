class Solution {
public:
    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int pre[13];
    int help(string &s)
    {
        
        int m=(s[0]-'0')*10+s[1]-'0';
        int day=(s[3]-'0')*10+s[4]-'0';
        return pre[m-1]+day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        pre[0]=0;
         for(int i=1;i<=12;i++)
            pre[i]=pre[i-1]+d[i-1];
        int a=help(arriveAlice);
        int b=help(leaveAlice);
        int c=help(arriveBob);
        int d=help(leaveBob);
      return max(0,min(b,d)-max(a,c)+1);
        
    }
};