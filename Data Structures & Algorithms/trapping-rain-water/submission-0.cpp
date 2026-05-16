class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int res = 0, n = height.size(), l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];

        while (l < r) {
            if (maxL <= maxR) {
                l++;
                maxL = max(maxL, height[l]);
                res += maxL - height[l];
            } else {
                r--;
                maxR = max(maxR, height[r]);
                res += maxR - height[r];
            }
        }

        return res;
    }
};
