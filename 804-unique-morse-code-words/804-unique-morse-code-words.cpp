class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
          vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
      unordered_set<string> s;
        
        for(auto &x:words)
        {
            string str="";
            for(auto &c:x)
            {
                str+=d[c-'a'];
            }
            s.insert(str);
        }
        return s.size();
    }
};