class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int ans=0;
        m[0]=1;
        int s=0;
        for(auto x:nums){
            s+=x;
            if(m.count(s-k)>0){
                ans+=m[s-k];
            }
            m[s]++;
        }
        return ans;
    }
};