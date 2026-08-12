class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int arrs;
        int maxf=INT_MIN;
        for(int i=0;i<n;i++){
            arrs+=nums[i];
            maxf=max(arrs,maxf);
            if (arrs<0){
                arrs=0;
            }
        }
    
    return maxf;}
};