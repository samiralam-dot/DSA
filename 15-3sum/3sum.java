
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        int n = nums.length;

        HashSet<List<Integer>> st = new HashSet<>();

        for (int i = 0; i < n; i++) {
            m.put(nums[i], i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int need = -(nums[i] + nums[j]);

                if (m.containsKey(need)) {
                    int idx = m.get(need);

                    if (idx != i && idx != j) {
                        List<Integer> temp = new ArrayList<>();

                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(need);

                        Collections.sort(temp);
                        st.add(temp);
                    }
                }
            }
        }

        return new ArrayList<>(st);
    }
}
