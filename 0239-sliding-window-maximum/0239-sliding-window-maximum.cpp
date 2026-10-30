class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        vector<int> q;
        int head = 0;

        for (int i = 0; i < n; ++i) {
           
            if (head < q.size() && q[head] <= i - k) {
                ++head;
            }

   
            while (q.size() > head && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            q.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[q[head]]);
            }
        }

        return result;
    }
};