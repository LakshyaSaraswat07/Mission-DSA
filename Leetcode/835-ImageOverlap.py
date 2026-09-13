class Solution:
  def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
    n = len(img1)

    ones1 = []
    ones2 = []

    for r in range(n):
      for c in range(n):
        if img1[r][c] == 1:
          ones1.append((r, c))

        if img2[r][c] == 1: 
          ones2.append((r, c))

    size = 2 * n - 1
    count = [0] * (size * size)

    result = 0

    for r1, c1 in ones1:
      for r2, c2 in ones2:
        dx = r2 - r1 + n - 1
        dy = c2 - c1 + n - 1

        key = dx * size + dy

        count[key] += 1
        result = max(result, count[key])

    return result
