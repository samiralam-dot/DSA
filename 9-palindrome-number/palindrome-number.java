class Solution {
    public boolean isPalindrome(int x) {
        String s=String.valueOf(x);
       int n=s.length();
       int i=0,j=n-1;
       while(i<j){
        if(s.charAt(i)!=s.charAt(j))return false;
        i++;j--;
       }
       return true;

        
    }
}