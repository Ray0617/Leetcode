public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split("\\.");
        String[] nums2 = version2.split("\\.");
        int i = 0;
        while (i < nums1.length || i < nums2.length) {
            int ver1 = 0;
            if (i < nums1.length)
                ver1 = Integer.valueOf(nums1[i]);
            int ver2 = 0;
            if (i < nums2.length)
                ver2 = Integer.valueOf(nums2[i]);
            if (ver1 < ver2)
                return -1;
            if (ver1 > ver2)
                return 1;
            i++;
        }
        return 0;
    }
}