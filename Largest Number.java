public class Solution {
    private int SignificantDigitComparatorStr(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int n = Math.min(n1, n2);
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) > str2.charAt(i))
                return 1;
            else if (str1.charAt(i) < str2.charAt(i))
                return -1;
        }
        if (n1 == n2)
            return 0;
        if (n1 < n2)
            return SignificantDigitComparatorStr(str1, str2.substring(n1));
        else
            return SignificantDigitComparatorStr(str1.substring(n2), str2);
        
    }
    class SignificantDigitComparator implements Comparator<Integer> {
        @Override
	    public int compare(Integer n1, Integer n2) {
	        return SignificantDigitComparatorStr(n1.toString(), n2.toString());
	    }
	}
    public String largestNumber(int[] num) {
        Integer[] nums = new Integer [num.length];
        for (int i = 0; i < num.length; i++)
            nums[i] = num[i];
        Arrays.sort(nums, new SignificantDigitComparator());
        if (nums.length == 0 || nums[nums.length - 1] == 0)
            return "0";
        StringBuilder result = new StringBuilder();
        for (int i = nums.length - 1; i >= 0; i--) {
            result.append(nums[i].toString());
        }
        return result.toString();
    }
}