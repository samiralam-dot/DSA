class Solution {
   
 HashMap<ArrayList<Integer>,Integer>mp=new HashMap<>();

    public int solve(int i,int j,int n,int m){
         if(i==n-1&&j==m-1)return 1;
        if(i>=n||j>=m)return 0;
        ArrayList<Integer>key=new ArrayList<>();
        key.add(i);
        key.add(j);
        if(mp.containsKey(key))return mp.get(key);
        int d=0,r=0;
        if(i+1<n){
            d+=solve(i+1,j,n,m);
        }
        if(j+1<m){
            r+=solve(i,j+1,n,m);
        }
       mp.put(key,d+r);
       return d+r;
    }

    public int uniquePaths(int m, int n) {
            mp.clear();
        return solve(0,0,m,n);

        
    }
}