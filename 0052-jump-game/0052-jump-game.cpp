class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size(), reach = 0;
        for (int i = 0; i < n; i++) {
            if (i > reach) return false;
            reach = max(reach, i + a[i]);
        }
        return true;
    }
};
