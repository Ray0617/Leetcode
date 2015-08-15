#include "leetcode.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        size_t start = 0;
        while (start != string::npos) {
            start++;
            auto end = path.find(start);
            auto sub = (end == string::npos) ? path.substr(start) : path.substr(start, end - start);
            start = end;
            if (sub == "." || sub == "")
                continue;
            if (sub == ".." && !dir.empty()) {
                dir.pop_back();
                continue;
            }
            dir.push_back(sub);
        }
        string result;
        for (auto d : dir) {
            result.push_back('/');
            result += d;
        }
        if (result.empty())
            return "/";
        return result;
    }
};

int main() {
	Solution sol;
	auto result = sol.simplifyPath("///");
	return 0;
}
