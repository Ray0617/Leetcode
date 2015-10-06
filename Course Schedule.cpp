class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, set<int>> before;
        map<int, set<int>> after;
        for (auto p : prerequisites) {
            before[p.first].insert(p.second);
            after[p.second].insert(p.first);
        }
        set<int> pendings;
        for (int i = 0; i < numCourses; i++) {
            if (before.find(i) == before.end())
                pendings.insert(i);
        }
        while (!pendings.empty()) {
            int course = *pendings.begin();
            pendings.erase(course);
            auto it = after.find(course);
            if (it != after.end()) {
                for (auto c : it->second) {
                    before[c].erase(course);
                    if (before[c].empty()) {
                        before.erase(c);
                        pendings.insert(c);
                    }
                }
            }
        }
        return before.empty();
    }
};

