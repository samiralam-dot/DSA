class Solution {
public:
vector<int>bit;
int n=1e5;
const int mod=1e9+7;


void update(int v){
    while(v<=n){
        bit[v]++;
        v+=(v&-v);
    }
}

int query(int x){
    int s=0;
    while(x>0){
        s+=bit[x];
        x-=(x&-x);
    }
    return s;
}


    int createSortedArray(vector<int>& ins) {
        bit.resize(n+1,0);
        int cost=0;
        for(auto x:ins){
            int sm=query(x-1);
            int gt=query(n)-query(x);
            
            cost=(cost+min(sm,gt))%mod;
            update(x);
        }
        return cost;
        
    }
};