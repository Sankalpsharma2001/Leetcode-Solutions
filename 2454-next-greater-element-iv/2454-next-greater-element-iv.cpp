class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
         int n = nums.size();
        vector<int> ans(nums.size(), -1);
        vector<int> st, st2, tmp;
        for(int i = 0; i < n; i++) {
            while(!st2.empty() && nums[st2.back()] < nums[i]) {
                ans[st2.back()] = nums[i];
                st2.pop_back();
            }
            while(!st.empty() && nums[st.back()] < nums[i]) {
                tmp.push_back(st.back());
                st.pop_back();
            }
            while(!tmp.empty()) {
                st2.push_back(tmp.back());
                tmp.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};