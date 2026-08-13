class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size(), total = accumulate(a.begin(), a.end(), 0);
        int window = n - k, sum = accumulate(a.begin(), a.begin() + window, 0), mn = sum;
        for (int i = window; i < n; i++) {
            sum += a[i] - a[i - window];
            mn = min(mn, sum);
        }
        return total - mn;
    }
};
