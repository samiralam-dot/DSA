class Solution {
    String ans = "";

    public void check(String s, int l, int r) {
        int n = s.length();

        while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }

        if (ans.length() < r - l - 1) {
            ans = s.substring(l + 1, r);
        }
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        ans = "";

        for (int i = 0; i < n; i++) {
            check(s, i, i);       // Odd length
            check(s, i, i + 1);   // Even length
        }

        return ans;
    }
}