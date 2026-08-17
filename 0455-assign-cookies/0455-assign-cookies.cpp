class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, right = 0;
        int m = g.size(), n = s.size();
        while (l < m && right < n) {
            if (g[l] <= s[right]) {
                l++;
                right++;
            } else {
                right++;  
            }
        }
        return l;  
    }
};
