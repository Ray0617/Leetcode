class Solution {
public:
    void letterCombinations(string prefix, string digits, vector<string>& vec)
    {
        if (digits.empty())
        {
            vec.push_back(prefix);
            return;
        }

        char num = digits[0];
        digits = digits.substr(1);
        
        switch(num)
        {
            case '2': 
                letterCombinations(prefix + "a", digits, vec);
                letterCombinations(prefix + "b", digits, vec);
                letterCombinations(prefix + "c", digits, vec);
                break;
            case '3': 
                letterCombinations(prefix + "d", digits, vec);
                letterCombinations(prefix + "e", digits, vec);
                letterCombinations(prefix + "f", digits, vec);
                break;
            case '4': 
                letterCombinations(prefix + "g", digits, vec);
                letterCombinations(prefix + "h", digits, vec);
                letterCombinations(prefix + "i", digits, vec);
                break;
            case '5': 
                letterCombinations(prefix + "j", digits, vec);
                letterCombinations(prefix + "k", digits, vec);
                letterCombinations(prefix + "l", digits, vec);
                break;
            case '6': 
                letterCombinations(prefix + "m", digits, vec);
                letterCombinations(prefix + "n", digits, vec);
                letterCombinations(prefix + "o", digits, vec);
                break;
            case '7': 
                letterCombinations(prefix + "p", digits, vec);
                letterCombinations(prefix + "q", digits, vec);
                letterCombinations(prefix + "r", digits, vec);
                letterCombinations(prefix + "s", digits, vec);
                break;
            case '8': 
                letterCombinations(prefix + "t", digits, vec);
                letterCombinations(prefix + "u", digits, vec);
                letterCombinations(prefix + "v", digits, vec);
                break;
            case '9': 
                letterCombinations(prefix + "w", digits, vec);
                letterCombinations(prefix + "x", digits, vec);
                letterCombinations(prefix + "y", digits, vec);
                letterCombinations(prefix + "z", digits, vec);
                break;
            default:
                letterCombinations(prefix + num, digits, vec);
                break;
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        letterCombinations("", digits, ret);
        return ret;
    }
};