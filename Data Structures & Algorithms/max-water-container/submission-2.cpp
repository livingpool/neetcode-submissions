class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0, n = heights.size(), l = 0, r = n-1;
        while (l < r) {
            cout << "l: " << l << ", r: " << r << endl; 
            int curr = min(heights[l], heights[r]) * (r - l);
            if (curr > res) res = curr;
            if (heights[l] > heights[r]) r--;
            else l++;
        }
        return res;
    }
};
