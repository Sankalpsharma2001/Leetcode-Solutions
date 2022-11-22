class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0,1,0}); // pos,speed,steps
        while(!q.empty())
        {
            vector<int> t=q.front();
            q.pop();
            int pos=t[0];
            int speed=t[1];
            int steps=t[2];
            if(pos==target)
                return steps;
            //A
            if(pos+speed>0 && pos+speed<=1e4+10)
            {
               q.push({pos+speed,2*speed,steps+1}); 
            }
            
            if(speed>0 && (pos+speed)>target)
            {
                q.push({pos,-1,steps+1});
            }
            if(speed<0 && pos+speed<target)
            {
                q.push({pos,1,steps+1});
            }
        }
        return -1;
    }
};