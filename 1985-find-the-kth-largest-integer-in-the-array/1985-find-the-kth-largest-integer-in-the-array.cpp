class Solution {
public:
    struct com{
        bool operator()(string &s1,string &s2)
        {
            if(s1.length()>s2.length()) return true;
            else if(s2.length()>s1.length()) return false;
            else
            {
                for(int i=0;i<s1.length();i++)
                {
                    if(s1[i]-'0'>s2[i]-'0') return true;
                    else if(s1[i]-'0'<s2[i]-'0') return false;
                }
            }
            return false;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        //min heap
        priority_queue<string,vector<string>,com> pq;
        for(auto it:nums) {
            pq.push(it);
          
            if(pq.size()>k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};