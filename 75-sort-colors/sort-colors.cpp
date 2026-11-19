class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int one=0,z=0,tw=0;
        for(auto x:nums){
            if(x==0)z++;
            else if(x==1)one++;
            else tw++;
        }

        int j=0;
        while(z--){
            nums[j]=0;
            j++;
        }
        while(one--){
            nums[j]=1;
            j++;
        }
        while(j<n){
            nums[j]=2;
            j++;
        }
     
    }
};