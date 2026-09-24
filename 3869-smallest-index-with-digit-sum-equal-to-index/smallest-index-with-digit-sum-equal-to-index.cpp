class Solution {
public:

int sum(int n){
    int r=0;
    while(n>0){
        r+=n%10;
        n/=10;
    }
    return r;
}
    int smallestIndex(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            if(sum(nums[i])==i)return i;
        }
        return -1;
        
    }
};