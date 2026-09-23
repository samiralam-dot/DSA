class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>ban;
        for(auto x:banned)ban.insert(x);
        vector<int>v;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(ban.count(i))continue;
            if(maxSum-i>=0){
                maxSum-=i;
                ans++;
            }
            
        }
        return ans;

        
    }
};