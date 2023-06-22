class Solution {
public:
    int minMoves(vector<int>& nums) {
            int n = nums.size();
      
        int minimum_element =*min_element(nums.begin(),nums.end());
        int answer = 0;
        
        for(int i=0; i<n; i++)
        {
            answer += (nums[i] - minimum_element);
        }
        
        return answer;
    }
};