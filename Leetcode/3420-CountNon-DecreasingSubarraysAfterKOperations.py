import collections

class Solution:
    def countNonDecreasingSubarrays(self, nums: list[int], k: int) -> int:
        ans = 0
        cost = 0
        dq = collections.deque()
        j = len(nums) - 1
        
        # Iterate backwards from right to left
        for i, num in reversed(list(enumerate(nums))):
            # Maintain a monotonic decreasing deque of indices
            while dq and nums[dq[-1]] < num:
                l = dq.pop()
                r = dq[-1] if dq else j + 1
                cost += (r - l) * (num - nums[l])
            dq.append(i)
            
            # If the current cost exceeds k, shrink the window from the right (j)
            while cost > k:
                cost -= nums[dq[0]] - nums[j]
                if dq[0] == j:
                    dq.popleft()
                j -= 1
                
            # All valid subarrays starting at `i` and ending up to `j` have cost <= k
            ans += j - i + 1
            
        return ans
