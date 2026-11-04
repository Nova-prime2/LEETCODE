class Solution {
    multiset<int> left, right;
    long long sumLeft = 0, sumRight = 0;

    void rebalance() {
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            int v = *it;
            left.erase(it);
            sumLeft -= v;
            right.insert(v);
            sumRight += v;
        }

        while (left.size() < right.size()) {
            auto it = right.begin();
            int v = *it;
            right.erase(it);
            sumRight -= v;
            left.insert(v);
            sumLeft += v;
        }
    }

    void add(int v) {
        if (left.empty() || v <= *left.rbegin()) {
            left.insert(v);
            sumLeft += v;
        } else {
            right.insert(v);
            sumRight += v;
        }
        rebalance();
    }

    void remove(int v) {
        auto it = left.find(v);
        if (it != left.end()) {
            left.erase(it);
            sumLeft -= v;
        } else {
            it = right.find(v);
            right.erase(it);
            sumRight -= v;
        }
        rebalance();
    }

    long long windowCost() const {
        long long median = *left.rbegin();
        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n);

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) cost[i] = windowCost();
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;

        for (int j = 0; j <= k; ++j) {
            for (int i = 1; i <= n; ++i) {
                dp[j][i] = dp[j][i - 1];

                if (j > 0 && i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i],
                                   dp[j - 1][i - x] + cost[i - 1]);
                }
            }
        }

        return dp[k][n];
    }
};