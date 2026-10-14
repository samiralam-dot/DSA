class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum==0||(num<=1&&sum>=10))return "";

        string ans="";
        ans+=to_string(min(sum,9));
        sum-=min(9,sum);


        for(int i=0;i<num-1;i++){
            ans+=to_string(min(9,sum));
            sum-=min(sum,9);
           
        }
     return sum>0?"":ans;


        
        
    }
};