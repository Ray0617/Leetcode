public class Solution {
    public int search(int A[], int target, int start, int end) {
        if (A[start] == target)
            return start;
        if (A[end] == target)
            return end;
        if (end <= start)
            return -1;
        int mid = (start + end) / 2;
        if ( A[start] < target && target < A[mid] || A[start] > A[mid] && (target > A[start] || target < A[mid]) )
            return search(A, target, start + 1, mid);
        else
            return search(A, target, mid, end - 1);
    }
    public int search(int[] A, int target) {
        if (A.length == 0)
            return -1;
        return search(A, target, 0, A.length - 1);
    }
}