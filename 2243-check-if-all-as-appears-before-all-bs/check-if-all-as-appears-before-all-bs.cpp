class Solution {
public:
    bool checkString(string s) {
        int a=0;
        for(auto x:s){
            if(x=='a')a++;
        }
        for(auto x:s){
            if(x=='a')a--;
            else{
                if(a>0)return false;
            }
        }
        return true;
        
    }
};