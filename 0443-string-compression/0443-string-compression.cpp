class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        for(int j=0;j<chars.size();j++)
        {
            int c=0;
            char ch=chars[j];
            while(j<chars.size() && ch==chars[j])
            {
                j++;
                c++;
            }
            j--;
            // cout<<c<<endl;
            if(c>1 && c<10)
            {
                chars[i++]=ch;
                chars[i++]=c+'0';
            }
            else if(c>=10)
            {
                 chars[i++]=ch;
                string str=to_string(c);
               
                for(int k=0;k<str.size();k++)
                {
                    chars[i++]=str[k];
                }
            }
            else
            {
                chars[i++]=ch;
            }
            
        }
        return i;
    }
};