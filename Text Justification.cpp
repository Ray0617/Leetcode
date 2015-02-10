class Solution {
public:
	string getLastLine(vector<string>& words_in_line, int L) {
		string line;
        for(unsigned i = 0; i < words_in_line.size(); i++) {
			if (i > 0)
				line.push_back(' ');
			line += words_in_line[i];
        }
		while (line.length() < L) {
			line.push_back(' ');
		}
		return line;
	}
	string getLine(vector<string>& words_in_line, int& len, int L) {
		string line;
        if (words_in_line.size() > 1) {
	        line = words_in_line[0];
            int space = (L - len) / (words_in_line.size() - 1);
            int mod = (L - len) % (words_in_line.size() - 1);
            string sep = "";
            for (int s = 0; s < space; s++) {
                sep += " ";
            }
            string sep_1 = sep + " ";
            for (int w = 1; w < words_in_line.size(); w++) {
                if (w <= mod)
                    line += sep_1;
                else
                    line += sep;
                line += words_in_line[w];
            }
        }
        else {
			if (!words_in_line.empty())
				line = words_in_line[0];
            while (line.length() < L)
                line.push_back(' ');
        }
        words_in_line.clear();
		len = 0;
		return line;
	}
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        vector<string> words_in_line;
        int len = 0;
		int i = 0;
		while (i < words.size()) {
            if (!words_in_line.empty() &&  len + words[i].length() + words_in_line.size() - 1 >= L) {
		        result.push_back(getLine(words_in_line, len, L));
			}
            words_in_line.push_back(words[i]);
            len += words[i].length();
			i++;
        }
		//last line
		result.push_back(getLastLine(words_in_line, L));
		return result;
    }
};