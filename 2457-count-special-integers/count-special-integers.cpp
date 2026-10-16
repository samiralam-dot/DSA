class Solution {
public:
int dp[12][2][2][1024];
int solve(int i,int t,int start,string &s,int mask)
    {
    if(i==s.size())return start;
    if(dp[i][t][start][mask]);
    int l=t?s[i]-'0':9;
    int ans=0;
    for(int d=0;d<=l;d++){
        int nt=(t&&(d==l));
        if(!start&&d==0){
            ans+=solve(i+1,nt,0,s,mask);
        }
        else{
            if(mask&(1<<d))continue;
            ans+=solve(i+1,nt,1,s,mask|(1<<d));
        }

    }
    return dp[i][t][start][mask]=ans;

}
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,s,0);

        
    }
};