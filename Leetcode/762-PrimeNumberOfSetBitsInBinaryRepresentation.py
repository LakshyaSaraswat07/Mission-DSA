class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        # A set of prime numbers up to the maximum possible number of set bits (around 20)
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        count = 0
        for num in range(left, right + 1):
            # Use the built-in bit_count() method to get the number of set bits
            if num.bit_count() in primes:
                count += 1
        return count
