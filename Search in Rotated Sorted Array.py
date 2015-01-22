class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        if (len(A) == 0):
            return -1;
        return self.searchInRange(A, target, 0, len(A) - 1)
    def searchInRange(self, A, target, start, end):
        if (A[start] == target):
            return start
        if (A[end] == target):
            return end
        if (end <= start):
            return -1
        mid = (start + end) / 2
        if ( A[start]<target and target<A[mid] or A[start]>A[mid] and (target>A[start] or target<A[mid]) ):
            return self.searchInRange(A, target, start+1, mid)
        else:
            return self.searchInRange(A, target, mid, end-1)
            