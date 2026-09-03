class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        map<char, int> s1;
        map<char, int> s2;

        for (int i = 0; i < s.length(); i++) {
            s1[s[i]]++;
            s2[t[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s1[s[i]] != s2[s[i]])
                return false;
        }

        return true;
    }
};