class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> cache;
		for (auto num : nums) {
			if (cache.find(num) != cache.end())
				return true;
			cache.insert(num);
		}
		return false;
	}
};


