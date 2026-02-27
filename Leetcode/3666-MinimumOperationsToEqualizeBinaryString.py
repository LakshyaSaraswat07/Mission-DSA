class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n = len(s)
        zeros = s.count('0')

        # Case 1: already all ones
        if zeros == 0:
            return 0

        # Case 2: if k == n
        if k == n:
            if zeros == n:
                return 1
            else:
                return -1

        # Try operations from 1 to n
        for ops in range(1, n + 1):

            # total flips done
            total_flips = ops * k

            # total flips must be enough to convert zeros
            if total_flips < zeros:
                continue

            # parity must match
            if (total_flips - zeros) % 2 == 0:
                return ops

        return -1
