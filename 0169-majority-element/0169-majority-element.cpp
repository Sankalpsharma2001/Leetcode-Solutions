class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
   
        //moore voting algo
        int v=0,c=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(v==0)
            { c=nums[i];
             v=1;
                
            }
            else
            {
                if(nums[i]==c)
                {v++;}
                else
                    v--;
            }
            
        }
        int cn=0,mn=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==c)
            {      cn++;
             mn=nums[i];
          }
        }
        return mn;
    }
};