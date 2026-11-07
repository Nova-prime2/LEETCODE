class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longest = 0;

        for (int x : values) {
           
            if (x == INT_MIN || !values.count(x - 1)) {
                int length = 1;
                int current = x;

                while (current != INT_MAX && values.count(current + 1)) {
                    ++current;
                    ++length;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};