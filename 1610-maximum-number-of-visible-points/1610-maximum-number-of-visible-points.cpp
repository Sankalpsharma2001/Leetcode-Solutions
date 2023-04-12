class Solution {
public:
     double PI = 3.141592;
    double getAngle(int x,int y)
    {
        // atan2(y,x) value range from -PI to PI then 180/PI convert to degree
        double angle=(atan2(y,x)*180)/PI; // convert to degree 
        if(angle<0) angle+=360;
        return angle;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        if(angle==360)
            return points.size();
          // 1 Move your location to (0, 0) and move all points.
        for (auto & p : points) {
            p[0] -= location[0];
            p[1] -= location[1];
        }
        
        vector<double> angles;
        int atLocation = 0;
        for (auto & p : points) {
            // 2 Keep count on all points already at location. 
            if (p[0] == 0 && p[1] == 0)
                atLocation++;
            else // 3 Use atan2 to convert all points into angles array.
                
                angles.push_back(getAngle(p[0], p[1]));
        }
        
            // 4 Sort angles array ascendingly.
        sort(angles.begin(), angles.end());
        // for(int i=0;i<angles.size();i++)
        //     cout<<angles[i]<<" ";
        int mx=0,n=angles.size();
        for(int i=0;i<n;i++)
        {
            angles.push_back(angles[i]+360);
        }
        for(int s=0,e=0;e<angles.size();e++)
        {
           if(angles[e]-angles[s]>angle)
           {
               s++;
           }
            mx=max(mx,e-s+1);
            
        }
        return mx+atLocation;
        
    }
};