public class Solution {
    public int uniquePaths(int m, int n) {
        // ((m-1)+(n-1))! / (m-1)! / (n-1)!
        int x = m - 1;
        int y = n - 1;
        // (x+y)!/(x!y!)=(x+y)*(x+y-1)*...*(1+y)/x!
        long result = 1;
        for (int i = 1; i <= x; i++)
        {
            result *= (y+i);
            result /= i;
        }
        return (int)result;
    }
}