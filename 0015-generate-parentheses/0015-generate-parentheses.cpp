class Solution {
public:

void dfs(int n,int open,int close,string curr,vector<string>&res){
    if (curr.size()==2*n) {res.push_back(curr); return;}
    if (open<n){
        dfs(n,open+1,close,curr+'(',res);
    }
    if (close<open){
        dfs(n,open,close+1,curr+')',res);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs(n,0,0,"",res);
        return res ;

    }
};


















