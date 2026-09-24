class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, x in enumerate(nums):
            # Calculate the sum of digits of x
            digit_sum = 0
            temp = x
            while temp > 0:
                digit_sum += temp % 10
                temp //= 10
            
            # Check if the digit sum equals the current index
            if digit_sum == i:
                return i
                
        return -1
