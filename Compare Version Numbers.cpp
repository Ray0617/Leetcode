class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1;
        ss1 << version1;
        
        stringstream ss2;
        ss2 << version2;
        
        while (!ss1.eof() || !ss2.eof()) {
            int ver1 = 0;
            if (!ss1.eof())
                ss1 >> ver1;
            int ver2 = 0;
            if (!ss2.eof())
                ss2 >> ver2;
            if (ver1 < ver2)
                return -1;
            else if (ver1 > ver2)
                return 1;
                
            char dot;
            ss1 >> dot;
            ss2 >> dot;
        }
        return 0;
    }
};