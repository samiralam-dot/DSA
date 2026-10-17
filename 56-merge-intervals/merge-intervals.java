class Solution {
    public int[][] merge(int[][] arr) {
        ArrayList<ArrayList<Integer>>ans=new ArrayList<>();
        Arrays.sort(arr,(a,b)->Integer.compare(a[0],b[0]));
        int s=arr[0][0];
        int e=arr[0][1];
        int n=arr.length;
        for(int i=1;i<n;i++){
            int sx=arr[i][0];
            int ex=arr[i][1];
            if(sx<=e){
                e=Math.max(ex,e);

            }
            else{
                ArrayList<Integer>temp=new ArrayList<>();
                temp.add(s);
                temp.add(e);
                ans.add(temp);
                s=sx;
                e=ex;
            }
        }
         ArrayList<Integer>temp=new ArrayList<>();
                temp.add(s);
                temp.add(e);
                ans.add(temp);
                int [][]res= new int[ans.size()][2];
                for(int i=0;i<ans.size();i++){
                    res[i][0]=ans.get(i).get(0);
                    res[i][1]=ans.get(i).get(1);
                }
        return res;
        
    }
}