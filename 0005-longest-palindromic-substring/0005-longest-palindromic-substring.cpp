class Solution {
    
    bool check(const string &c) {
        int n = c.size();
        for (int i = 0; i < n / 2; i++) {
            if (c[i] != c[n - 1 - i]) return false;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            string c = "";
            for (int j = i; j < n; j++) {
                c += s[j];               
                if (check(c)) {          
                    if (c.size() > ans.size()) {
                        ans = c;          
                    }
                }
            }
        }
        return ans;
    }
};
