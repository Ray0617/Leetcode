public class Solution {
    public int largestRectangleArea(int[] arrHeight) {
        Deque<Integer> ascend = new ArrayDeque<Integer>();
        int maxArea = 0;
        List<Integer> height = new ArrayList<Integer>();
        for (int i = 0; i < arrHeight.length; i++) {
            height.add(arrHeight[i]);
        }
        height.add(0);
        for (int i = 0; i < height.size(); i++) {
            if (i > 0 && height.get(i) < height.get(i-1)) {
                while (!ascend.isEmpty()) {
                    int h = height.get(ascend.getLast());
                    if (h < height.get(i))
                        break;
                    ascend.removeLast();
                    int right = i;
                    int left = (ascend.isEmpty()?-1:ascend.peekLast()) + 1;
                    int area = h * (right - left);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
            ascend.add(i);
        }
        return maxArea;
    }
}