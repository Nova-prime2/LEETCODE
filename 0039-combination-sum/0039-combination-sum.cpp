class Solution {
public:
    void dfs(vector<int>&a,int t,int i,vector<int>&cur,vector<vector<int>>&res){
        if(t==0){res.push_back(cur);return;}
        if(i==a.size()||t<0) return;
        cur.push_back(a[i]);
        dfs(a,t-a[i],i,cur,res);
        cur.pop_back();
        dfs(a,t,i+1,cur,res);
    }
    vector<vector<int>> combinationSum(vector<int>&a,int t){
        vector<vector<int>> res;
        vector<int> cur;
        dfs(a,t,0,cur,res);
        return res;
    }
};
