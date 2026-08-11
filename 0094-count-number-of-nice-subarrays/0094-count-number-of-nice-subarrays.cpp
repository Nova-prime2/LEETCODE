class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;  // base case
        int sum = 0, ans = 0;

        for (int x : nums) {
            sum += (x % 2);  // odd → 1, even → 0
            if (freq.count(sum - k)) {
                ans += freq[sum - k];
            }
            freq[sum]++;
        }
        return ans;
    }
};
