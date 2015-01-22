class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if (len(strs) == 0):
            return ""
        index = 0
        for ch in strs[0]:
            for str in strs[1:]:
                if (len(str) <= index or str[index] != ch):
                    return strs[0][0:index]
            index = index + 1
        return strs[0][0:index]