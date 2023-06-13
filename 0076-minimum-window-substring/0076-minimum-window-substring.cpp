class Solution {
public:
     bool check(vector<int> &tmp,vector<int> &cnt){
        for(int i = 0; i < 128; i++){
            if(tmp[i]<cnt[i]){return false;}
        }
        return true;
    }
    string minWindow(string s, string t) {
           if(s.length()<t.length())return "";
        vector<int> cnt(128,0);
        for(auto &i: t){
            cnt[i]++;
        }
        int i = 0, j = 0, n = s.length();
        vector<int> tmp(128,0);
        string ans = "";
        int a = -1, b = n;
        while(i<n){
            tmp[s[i]]++;
            while(j<=i && check(tmp,cnt)){
                if(i-j+1 <= b){
                    b = i-j+1;
                    a = j;
                }
                tmp[s[j]]--;
                j++;
            }
            i++;
        }
        if(a==-1)return "";
        return s.substr(a,b);
    }
};