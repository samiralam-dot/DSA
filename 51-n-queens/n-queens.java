class Solution {

    TreeMap<Integer, Boolean> row = new TreeMap<>();
    TreeMap<Integer, Boolean> d1 = new TreeMap<>();
    TreeMap<Integer, Boolean> d2 = new TreeMap<>();

    List<List<String>> ans = new ArrayList<>();

    public boolean check(int i, int j, int n) {
        if (row.containsKey(i)) return false;
        if (d1.containsKey(i + j)) return false;
        if (d2.containsKey(i - j)) return false;

        return true;
    }

    public void solve(int col, int n, StringBuilder[] sb) {
        if (col == n) {
            List<String> temp = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                temp.add(sb[i].toString());
            }

            ans.add(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(i, col, n)) {

                sb[i].setCharAt(col, 'Q');

                row.put(i, true);
                d1.put(i + col, true);
                d2.put(i - col, true);

                solve(col + 1, n, sb);

                // Backtracking
                sb[i].setCharAt(col, '.');

                row.remove(i);
                d1.remove(i + col);
                d2.remove(i - col);
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        StringBuilder[] sb = new StringBuilder[n];

        for (int i = 0; i < n; i++) {
            sb[i] = new StringBuilder(".".repeat(n));
        }

        solve(0, n, sb);

        return ans;
    }
}