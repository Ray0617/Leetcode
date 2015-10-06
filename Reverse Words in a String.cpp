class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        string word;
        for (auto ch : s) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
            else {
                word.push_back(ch);
            }
        }
        if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
        s.clear();
        reverse(words.begin(), words.end());
        for (auto word : words) {
            if (!s.empty())
                s.push_back(' ');
            s += word;
        }
    }
};

