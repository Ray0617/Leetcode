class Solution {
public:
	bool valid(string s) {
		if (s == "0")
			return true;
		if (s[0] == '0')
		    return false;
		int n = atoi(s.c_str());
		return (n <= 255);
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		for (int len1 = 1; len1 <= 3; len1++) {
			if (len1 + 3 > s.length())
				break;
			string s1 = s.substr(0, len1);
			if (!valid(s1))
				continue;
			for (int len2 = 1; len2 <= 3; len2++) {
				if (len1 + len2 + 2 > s.length())
					break;
				string s2 = s.substr(len1, len2);
				if (!valid(s2))
					continue;
				for (int len3 = 1; len3 <= 3; len3++) {
					int len4 = s.length() - len1 - len2 - len3;
					if (len4 < 1 || len4 > 3)
						continue;
					string s3 = s.substr(len1 + len2, len3);
					string s4 = s.substr(len1 + len2 + len3, len4);
					if (valid(s3) && valid(s4)) {
						result.push_back(s1+"."+s2+"."+s3+"."+s4);
					}
				}
			}
		}
		return result;
	}
};


