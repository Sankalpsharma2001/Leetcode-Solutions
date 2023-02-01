class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string s=words[0];
        for(int i=1;i<words.size();i++)
        {
            if(s.size()+words[i].size()+1<=maxWidth)
            {
                s+=" "+words[i];
            }
            else
            {
                s=spaceJustifier(s,maxWidth,0);
                ans.push_back(s);
                s=words[i];
            }
        }
        s=spaceJustifier(s,maxWidth,1);
        ans.push_back(s);
        return ans;
    }
    string spaceJustifier(string str, int maxWidth, int isLast)
    {
        if(str.size()==maxWidth) return str;
        int space=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ') space++;
        }
        int spaceInserted=maxWidth-str.size();
        if(space==0 || isLast==1)
        {
           for(int i=0;i<spaceInserted;i++)
               str+=' ';
            return str;
        }
        int eachSlot=spaceInserted/space;
        int rem=spaceInserted%space;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ' && (eachSlot>0 || rem>0))
            {
                int noOfSpace=eachSlot;
                if(rem-->0) {noOfSpace++;}
                 str.insert(i, noOfSpace , ' ');
                i+=noOfSpace;
            }
        }
        return str;
        
        
        
    }
};