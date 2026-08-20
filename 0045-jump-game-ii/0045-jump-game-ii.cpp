class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size(), jumps = 0, curEnd = 0, far = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + a[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = far;
            }
        }
        return jumps;
    }
};
