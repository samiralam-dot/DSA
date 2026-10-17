class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans=0;
        HashSet<Character>st=new HashSet<>();
        int n=s.length();
        int i=0,j=0;
        while(j<n){
           if(st.contains(s.charAt(j))){
            while(i<n&&st.contains(s.charAt(j))){
                st.remove(s.charAt(i));
                i++;
            }
           }
           st.add(s.charAt(j));
           ans=Math.max(ans,j-i+1);
           j++;
        }
        return ans;
        
    }
}