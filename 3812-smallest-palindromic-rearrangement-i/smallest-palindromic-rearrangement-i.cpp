class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        string ans="";
        char od='*';
        for(auto x:m){
            int f=x.second;
            char c=x.first;
            if(f%2)od=c;
            for(int i=0;i<f/2;i++){
                ans+=c;
            }

        }

        string temp=ans;
        if(od!='*')ans+=od;
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
        
    }
};