class ProductOfNumbers:

    def __init__(self):
        # Initialize with 1 as a base multiplier for prefix products
        self.prefix = [1]

    def add(self, num: int) -> None:
        if num == 0:
            # Reset the prefix list because any product including 0 will be 0
            self.prefix = [1]
        else:
            # Append the new cumulative product
            self.prefix.append(self.prefix[-1] * num)

    def getProduct(self, k: int) -> int:
        # If k is >= len(self.prefix), a 0 was encountered within the last k numbers
        if k >= len(self.prefix):
            return 0
        
        # Divide the latest cumulative product by the product right before the last k elements
        return self.prefix[-1] // self.prefix[-k - 1]
