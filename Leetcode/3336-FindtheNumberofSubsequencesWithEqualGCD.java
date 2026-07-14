import java.util.Arrays;

class Solution {
    private static final int MOD = 1_000_000_007;
    private int[][][] memo;
    private int[] nums;
    private int n;

    public int subsequencePairCount(int[] nums) {
        this.nums = nums;
        this.n = nums.length;
        
        // Find the maximum value in nums to size the memo table
        int maxVal = Arrays.stream(nums).max().getAsInt();
        
        memo = new int[n][maxVal + 1][maxVal + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxVal; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }

        // Subtract 1 because we initially include an empty subsequence pair (0, 0)
        return (solve(0, 0, 0) - 1 + MOD) % MOD;
    }

    private int solve(int index, int gcd1, int gcd2) {
        if (index == n) {
            return gcd1 == gcd2 ? 1 : 0;
        }

        if (memo[index][gcd1][gcd2] != -1) {
            return memo[index][gcd1][gcd2];
        }

        // Choice 1: Skip the current number
        long totalWays = solve(index + 1, gcd1, gcd2);

        // Choice 2: Add to the first subsequence
        totalWays = (totalWays + solve(index + 1, gcd(gcd1, nums[index]), gcd2)) % MOD;

        // Choice 3: Add to the second subsequence
        totalWays = (totalWays + solve(index + 1, gcd1, gcd(gcd2, nums[index]))) % MOD;

        return memo[index][gcd1][gcd2] = (int) totalWays;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
