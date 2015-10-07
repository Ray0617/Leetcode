class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> groups;
		for (auto str : strs) {
			string anagram = str;
			sort(anagram.begin(), anagram.end());
			groups[anagram].push_back(str);
		}
		vector<vector<string>> result;
		for (auto group : groups) {
			sort(group.second.begin(), group.second.end());
			result.push_back(group.second);
		}
		return result;
	}
};


