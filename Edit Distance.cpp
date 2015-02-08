
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > distance(word1.length() + 1);
        for (unsigned int i = 0; i <= word1.length(); i++) {
            distance[i].resize(word2.length() + 1);
        }
        for (unsigned int i = 0; i <= word1.length(); i++)
            distance[i][0] = i; // word1[0:i] -> null == delete i times
        for (unsigned int j = 0; j <= word2.length(); j++)
            distance[0][j] = j; // null -> word2[0:j] == insert j times

        for (unsigned int i = 1; i <= word1.length(); i++) {
            for (unsigned int j = 1; j <= word2.length(); j++) {
                //(insert word1[i], delete word1[i])
                int dist = min(distance[i-1][j] + 1, distance[i][j-1] + 1);
                //replace word1[i] with word2[j]]
                dist = min(dist, distance[i-1][j-1] + (word1[i-1]==word2[j-1]?0:1));
                distance[i][j] = dist;
            }
        }
        return distance[word1.length()][word2.length()];
    }
};