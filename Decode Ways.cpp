class Solution {
public:
    bool checkValid(char ch) {
        return ch >= '1' && ch <= '9';
    }
    bool checkValid(char ch1, char ch2) {
        return ch1 == '1' || (ch1 == '2' && ch2 <= '6');
    }
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		vector<int> decodings(s.length());
		for (int i = 0; i < s.length(); i++) {
		    decodings[i] = 0;
		    if (checkValid(s[i])) {
		        if (i == 0)
		            decodings[i] += 1;
		        else
			        decodings[i] += decodings[i-1];
		    }
		    if (i > 0 && checkValid(s[i-1], s[i])) {
		        if (i >= 2)
				    decodings[i] += decodings[i-2];
				else
				    decodings[i] += 1;
		    }
		}
		return decodings.back();
	}
};


