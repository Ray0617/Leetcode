
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> ascend;
        int max_area = 0;
        height.push_back(0);
        for (unsigned i = 0; i < height.size(); i++) {
            if (i > 0 && height[i] == height[i-1]) {
				ascend.back() = i;
				continue;
			}
            else if (i > 0 && height[i] < height[i-1]) {
                // calculate all possible value with the i-th bar
                while (!ascend.empty()) {
                    int h = height[ascend.back()];
					if (h < height[i])
						break;
					ascend.pop_back();
					if (h == height[i])
						break;
                    int right = i;
					int left = (ascend.empty()?-1:ascend.back()) + 1;
                    int area = h * (right - left);
                    if (area > max_area)
                        max_area = area;
                }
            }
            ascend.push_back(i);
        }
        return max_area;
    }
};