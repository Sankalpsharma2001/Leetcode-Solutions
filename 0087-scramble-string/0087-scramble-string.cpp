class Solution {
public:
    unordered_map<string,bool> m;
    bool check(string a,string b)
    {
        int n=a.size();
        if(a.compare(b)==0)return true;
        if(a.size()<=1) return false;
        string key=a+' '+b;
        if(m.find(key)!=m.end())
            return m[key];
        bool flag=false;
        for(int i=1;i<a.size();i++)
        {
            if(check(a.substr(0,i),b.substr(0,i)) && check(a.substr(i,n-i),b.substr(i,n-i)) ||
              check(a.substr(0,i),b.substr(n-i,i)) && check(a.substr(i,n-i),b.substr(0,n-i)) )
            {
                flag=true;
                break;
            }
        }
       return m[key]=flag;
    }
    bool isScramble(string s1, string s2) {
          if(s1.size()!=s2.size())
            return false;
      
        return check(s1,s2);
    }
};