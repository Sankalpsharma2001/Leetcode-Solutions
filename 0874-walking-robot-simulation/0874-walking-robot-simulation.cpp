class Solution {
public:
    double distance(int x,int y)
    {
        return (x*x+y*y);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> s;
        for(auto &it:obstacles)
        {
            s.insert({it[0],it[1]});
        }
        int x=0,y=0;
        int ans=INT_MIN;
        int north=0,east=0,south=0,west=0;
        north=1;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2)
            {
                 
            if(north)
            {
             west=1;
                north=0;
            }
           else if(south)
            {
                east=1;
                south=0;
            }
           else if(west)
            {
                south=1;
                west=0;
            }
           else if(east)
            {
                north=1;
                east=0;
            }
                
            }
           else if(commands[i]==-1)
            {
                 if(north)
            {
             east=1;
                north=0;
            }
           else if(south)
            {
                west=1;
                south=0;
            }
           else if(west)
            {
                north=1;
                west=0;
            }
           else if(east)
            {
                south=1;
                east=0;
            }
                  
            }
            else 
            {
                int c=commands[i];
                while(c--)
                {
                      if(north)
            {
                          if(s.find({x,y+1})!=s.end())
                    {
                        break;
                    }
              y++;
            }
            if(south)
            {
                if(s.find({x,y-1})!=s.end())
                    {
                        break;
                    }
                y--;
            }
            if(west)
            {
                if(s.find({x-1,y})!=s.end())
                    {
                        break;
                    }
                x--;
            }
            if(east)
            {
                if(s.find({x+1,y})!=s.end())
                    {
                        break;
                    }
               x++;
            }
                   
                    
               
                }
            }
             ans=max(ans,(int)distance(x,y));
           // cout<<x<<" "<<y<<" "<<ans<<endl; 
           
        }
        return ans;
    }
};