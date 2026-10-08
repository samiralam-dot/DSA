class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(auto x:tasks)m[x]++;
        int ans=0;
        for(auto x:m){
            int f=x.second;
            if(f==1)return -1;
            ans+=(f+2)/3;
        }
        return ans;
    }
};