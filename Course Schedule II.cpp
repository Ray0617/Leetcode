class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, set<int>> before;
        map<int, set<int>> after;
        for (auto prerequisite : prerequisites) {
            // prerequisite.first <- prerequisite.second
            after[prerequisite.second].insert(prerequisite.first);
            before[prerequisite.first].insert(prerequisite.second);
        }
        vector<int> result;
        set<int> pendings;
        for (int i = 0; i < numCourses; i++)
            if (before.find(i) == before.end())
                pendings.insert(i);
        while (!pendings.empty()) {
            int course = *(pendings.begin());
            result.push_back(course);
            pendings.erase(course);
            auto it = after.find(course);
            if (it != after.end()) {
                for (auto after_course : it->second) {
                    before[after_course].erase(course);
                    if (before[after_course].empty()) {
                        pendings.insert(after_course);
                        before.erase(after_course);
                    }
                }
            }
        }
        if (result.size() != numCourses)
            return vector<int>();
        return result;
    }
};

