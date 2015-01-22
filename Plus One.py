class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        if (len(digits) == 0):
            return digits
        index = len(digits) - 1
        while (index >= 0):
            digits[index] = digits[index] + 1;
            if (digits[index] < 10):
                return digits;
            # carry to next digit
            digits[index] = 0;
            index = index - 1;
        ret = [1]
        ret.extend(digits)
        return ret
