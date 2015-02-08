public class Solution {
    public int minDistance(String word1, String word2) {
        int[][] distance = new int [word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= word1.length(); i++)
            distance[i][0] = i;
        for (int i = 0; i <= word2.length(); i++)
            distance[0][i] = i;
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                int dist = Math.min(distance[i-1][j] + 1, distance[i][j-1] + 1);
                distance[i][j] = Math.min(dist, distance[i-1][j-1] + (word1.charAt(i-1)==word2.charAt(j-1)?0:1));
            }
        }
        return distance[word1.length()][word2.length()];
    }
}