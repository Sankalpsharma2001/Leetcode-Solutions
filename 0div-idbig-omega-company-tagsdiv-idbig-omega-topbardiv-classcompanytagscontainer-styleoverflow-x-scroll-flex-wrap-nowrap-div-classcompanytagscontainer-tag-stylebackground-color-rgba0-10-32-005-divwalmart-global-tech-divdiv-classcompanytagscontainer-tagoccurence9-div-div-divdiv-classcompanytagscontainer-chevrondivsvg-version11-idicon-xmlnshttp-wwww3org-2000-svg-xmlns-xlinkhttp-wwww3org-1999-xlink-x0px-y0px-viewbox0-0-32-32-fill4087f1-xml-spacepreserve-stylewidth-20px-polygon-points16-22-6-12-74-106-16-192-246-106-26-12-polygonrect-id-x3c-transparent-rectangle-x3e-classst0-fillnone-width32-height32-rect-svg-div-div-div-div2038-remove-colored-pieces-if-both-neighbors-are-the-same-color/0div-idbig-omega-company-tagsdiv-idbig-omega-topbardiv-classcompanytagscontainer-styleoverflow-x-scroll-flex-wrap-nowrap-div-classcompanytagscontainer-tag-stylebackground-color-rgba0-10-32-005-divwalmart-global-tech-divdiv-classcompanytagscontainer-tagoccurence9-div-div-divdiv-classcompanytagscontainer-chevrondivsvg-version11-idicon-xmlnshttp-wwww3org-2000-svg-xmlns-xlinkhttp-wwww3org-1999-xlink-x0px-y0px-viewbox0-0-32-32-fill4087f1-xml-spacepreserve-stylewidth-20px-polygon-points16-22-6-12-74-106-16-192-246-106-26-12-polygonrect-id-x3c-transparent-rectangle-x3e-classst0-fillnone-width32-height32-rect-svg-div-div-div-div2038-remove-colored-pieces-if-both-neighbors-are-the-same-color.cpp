class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int countAlice=0,countBob=0;
        for(int i=1;i<n-1;i++)
        {
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1])
            {
                if(colors[i]=='A')
                {
                    countAlice++;
                }
                else
                {
                    countBob++;
                }
            }
        }
        return countAlice>countBob;
    }
};