class Solution {
public:

map<int,int>m;

    int fib(int n) {
        if(n==0||n==1)return n;
        m[0]=0;
        m[1]=1;
        for(int i=2;i<=n;i++){
            m[i]=m[i-1]+m[i-2];
        }
        return m[n];
        
        
        

        
    }
};