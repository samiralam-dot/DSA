class Solution {
    public int reverse(int x) {
        boolean ne=x<0;
        String s=String.valueOf(Math.abs((long)x));
        StringBuilder sb=new StringBuilder(s);
        sb.reverse();
        String ans=sb.toString();
        long va=Long.parseLong(ans);
        if(ne)va*=-1;
        if(va<Integer.MIN_VALUE||va>Integer.MAX_VALUE)return 0;
        return (int)va; 


        
    }
}