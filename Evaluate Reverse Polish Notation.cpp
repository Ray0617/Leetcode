class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> vals;
		for (auto token : tokens) {
			if (token == "+") {
				int val = vals.back();
				vals.pop_back();
				vals.back() += val;
			} else if (token == "-") {
				int val = vals.back();
				vals.pop_back();
				vals.back() -= val;			
			} else if (token == "*") {
				int val = vals.back();
				vals.pop_back();
				vals.back() *= val;			
			} else if (token == "/") {
				int val = vals.back();
				vals.pop_back();
				vals.back() /= val;			
			} else {
				vals.push_back(atoi(token.c_str()));
			}
		}
		return vals.back();
	}
};


