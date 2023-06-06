class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        	int n = arr.size(), mini = INT_MAX, maxi = INT_MIN;
	unordered_map<int, int>mp;
	for(auto &it : arr) {
		mini = min(mini, it);
		maxi = max(maxi, it);
		mp[it]++;
	}    

	if((maxi - mini) % (n-1) != 0) return false;  // check for existence of an A.P.
	int diff = (maxi - mini) / (n-1);

	while(n--) {
		if(!mp[mini]) return false;
		mini += diff;
	}
	return true;
    }
};