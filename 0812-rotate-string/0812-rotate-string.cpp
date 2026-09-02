class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string e = s + s;
        return e.find(goal) != string::npos;
    }
};
