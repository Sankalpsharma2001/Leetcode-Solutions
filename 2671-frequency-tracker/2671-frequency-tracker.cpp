class FrequencyTracker {
public:
     unordered_map<int,int> mp1,fre;
    FrequencyTracker() {
      
    }
    
    void add(int n) {
          if(fre[mp1[n]] > 0) {
            fre[mp1[n]]--;
        }
        mp1[n]++;
        fre[mp1[n]]++;
    }
    
    void deleteOne(int n) {
       
   if(mp1[n] > 0) {
            fre[mp1[n]]--;
            mp1[n]--;
            fre[mp1[n]]++;
        }
        
       
    }
    
    bool hasFrequency(int f) {
        return fre[f] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */