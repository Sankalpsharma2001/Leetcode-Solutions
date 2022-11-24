class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      vector<int>right(arr.size()+1);
        right[arr.size()] = INT_MAX;
        
        for(int i =arr.size()-1 ; i>= 0; i--){
           right[i] = min(right[i+1], arr[i]);
        }
        int left_max = INT_MIN;
        int countChunks =0;
        for(int i =0; i<arr.size(); i++){
            left_max = max(left_max, arr[i]);
            if(left_max <= right[i+1]) countChunks++;  
        }
        return countChunks;
    }
};