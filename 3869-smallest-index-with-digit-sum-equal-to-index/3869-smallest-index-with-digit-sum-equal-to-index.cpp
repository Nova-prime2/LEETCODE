class Solution {
    int check(int n,int i){
        int e=n;
        int sum=0;
        while(e>0){
            sum+=e%10;
            e=e/10;
        }
        if (sum==i) return i;
        else return -1;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
           int  ans= check(nums[i],i);
           if (ans!=-1) return i;
        }
        return -1;
    }
};