class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};

        for (char c : s) {
            freq[c]++;
        }

        string ans = "";

        for (int f = s.length(); f >= 1; f--) {
            for (int i = 0; i < 256; i++) {
                if (freq[i] == f) {
                    ans += string(f, char(i));
                }
            }
        }

        return ans;
    }
};