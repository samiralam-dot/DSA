class Solution {
public:

map<int,int>m;

    int fib(int n) {
        if(n==0||n==1)return n;
        if(m[n]>0)return m[n];
        
        return  m[n]=fib(n-1)+fib(n-2);

        
    }
};