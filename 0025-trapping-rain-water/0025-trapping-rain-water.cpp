class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int l = 0, r = height.size() - 1;
        int left_max = 0, right_max = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (left_max > height[l])
                    total += left_max - height[l];
                else
                    left_max = height[l];

                l++;
            } else {
                if (right_max > height[r])
                    total += right_max - height[r];
                else
                    right_max = height[r];

                r--;
            }
        }

        return total;
    }
};