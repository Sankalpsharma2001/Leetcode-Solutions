class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        string st; 
        int n=s.size();
        int numberofLettersleft=0;
        for(auto &e: s){
            if(e==letter){
                numberofLettersleft++;  
            }
        }
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && s[i]<st.back() && st.size()-1+n-i>=k && repetition+(st.back()==letter ? 1 : 0)<=numberofLettersleft )
            {
                // st.size()-1+n-i>=k after removing there is sufficient element so we can make its size k
   // repetition+(st.back()==letter ? 1 : 0)<=numberofLettersleft  we pop out repeated letter so we have to find +1 more element of that letter             
                if(st.back()==letter){
                    repetition++;  // if unique letter, increase repetition since we are removing a unique letter from stack
                }
                st.pop_back();
            }
            
            if((st.empty() || st.size()<k) && st.size()+1+repetition+(s[i]==letter ? -1 : 0)<=k){
                st.push_back(s[i]);
                   if(s[i]==letter){ // since we are pushing a unique element in stack, decrease repetition
                    repetition--;
                }
            }
            if(s[i]==letter){  // if this is unique character, decrease freq of unique letters 
                numberofLettersleft--;
            }
            
        }
        return st;
        
        
    }
};