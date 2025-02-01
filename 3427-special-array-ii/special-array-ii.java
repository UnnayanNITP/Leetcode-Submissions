class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] prefSum = new int[n];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1];
            if (nums[i - 1] % 2 == nums[i] % 2) {
                prefSum[i]++;
            }
        }

        int qn = queries.length;
        boolean[] ans = new boolean[qn];

        // The n==1 case is now handled correctly.
        if (n == 1) {
            for (int i = 0; i < qn; i++) {
                ans[i] = true; // All subarrays of length 1 ARE special.
            }
            return ans; 
        }

        for (int i = 0; i < qn; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            int count = prefSum[v] - (u > 0 ? prefSum[u] : 0);
            ans[i] = count == 0;
        }

        return ans;
    }
}