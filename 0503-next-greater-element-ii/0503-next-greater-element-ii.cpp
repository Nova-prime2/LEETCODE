class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
    vector<int>array(n,-1);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n+i;j++){
            int index=j%n;
            if (nums[index]>nums[i]){
                array[i]=nums[index];
                break;
            }
        }
    }
    return array;
    }
};