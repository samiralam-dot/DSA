class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int val1=0,val2=0;
        for(auto x:nums1)val1^=x;
                for(auto x:nums2)val2^=x;
        int ans=0;
        int n1=nums1.size(),n2=nums2.size();

        if(n1%2)ans^=val2;
        if(n2%2)ans^=val1;
        return ans;

        
    }
};