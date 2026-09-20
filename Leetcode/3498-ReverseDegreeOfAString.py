class Solution:
    def reverseDegree(self, s: str) -> int:
        total_sum = 0
      
        # Iterate through the string with 1-indexed positions
        for position, char in enumerate(s, 1):
            # Calculate reverse alphabetical position
            # 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            reverse_alphabet_position = 26 - (ord(char) - ord('a'))
          
            # Add the product of position and reverse alphabet position to total
            total_sum += position * reverse_alphabet_position
          
        return total_sum
