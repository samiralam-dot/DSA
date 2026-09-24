class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        map<int,int>m;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                cnt++;
                m[cnt]=i;
            }
        }
        vector<int>ans;
        for(auto x:queries){
            if(m.count(x)){
                ans.push_back(m[x]);
            }
            else ans.push_back(-1);
        }
        return ans;
        
    }
};