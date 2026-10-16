class Solution {
    public int reverse(int x) {
        boolean neg = x < 0;
        String s = String.valueOf(Math.abs((long) x));

        StringBuilder sb = new StringBuilder(s);
        sb.reverse();

        try {
            int ans = Integer.parseInt(sb.toString());
            return neg ? -ans : ans;
        } catch (NumberFormatException e) {
            return 0;
        }
    }
}