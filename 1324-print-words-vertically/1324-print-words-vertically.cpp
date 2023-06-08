class Solution {
public:
    vector<string> printVertically(string s) {
            s+= " "; //adding space at the end for easy calculation of chunk strings.
    vector<string> temp;  
    vector<string> ans;  
    string str = "";
    int maxi = INT_MIN;  
    for(int i =0 ; i<s.length(); i++)
    {
        if(s[i]==' ')
        {
            temp.push_back(str);
            int sz = str.size();
            maxi = max(sz,maxi);
            str = "";
        }
        else str += s[i];
    }
    
    for(int i = 0; i<maxi; i++)
    {
        for(auto &it: temp)
        {
            if(i >= it.length()) str += " ";
            else str += it[i];
        }
        int n = str.size()-1;  //storing the length of current string.
        while(str[n]==' ')  //this loop is for removing extra spaces from the end.
        {
            str.pop_back();
            n--;
        }
        ans.push_back(str);
        str = "";
    }
    return ans;
    }
};