class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:

        # Sort costs in ascending order to buy cheapest ice creams first
        costs.sort()
      
        # Iterate through sorted costs and buy ice creams while we have enough coins
        for index, cost in enumerate(costs):
            # If current ice cream cost exceeds remaining coins, return count
            if coins < cost:
                return index
          
            # Deduct the cost from available coins
            coins -= cost
      
        # If we can afford all ice creams, return total count
        return len(costs)
