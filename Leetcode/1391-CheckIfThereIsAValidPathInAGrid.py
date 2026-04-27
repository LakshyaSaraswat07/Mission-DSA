class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
    
        rows, cols = len(grid), len(grid[0])
      
        # Initialize parent array for Union-Find
        # Each cell is initially its own parent
        parent = list(range(rows * cols))
      
        def find(node: int) -> int:
           
            if parent[node] != node:
                parent[node] = find(parent[node])  # Path compression
            return parent[node]
      
        def connect_left(row: int, col: int) -> None:
           
            # Check if left neighbor exists and can connect from right
            # Streets 1, 4, 6 have right openings
            if col > 0 and grid[row][col - 1] in (1, 4, 6):
                current_root = find(row * cols + col)
                left_root = find(row * cols + col - 1)
                parent[current_root] = left_root
      
        def connect_right(row: int, col: int) -> None:
            """Connect current cell with right neighbor if compatible."""
            # Check if right neighbor exists and can connect from left
            # Streets 1, 3, 5 have left openings
            if col < cols - 1 and grid[row][col + 1] in (1, 3, 5):
                current_root = find(row * cols + col)
                right_root = find(row * cols + col + 1)
                parent[current_root] = right_root
      
        def connect_up(row: int, col: int) -> None:
           
            # Check if upper neighbor exists and can connect from bottom
            # Streets 2, 3, 4 have bottom openings
            if row > 0 and grid[row - 1][col] in (2, 3, 4):
                current_root = find(row * cols + col)
                up_root = find((row - 1) * cols + col)
                parent[current_root] = up_root
      
        def connect_down(row: int, col: int) -> None:
           
            # Check if lower neighbor exists and can connect from top
            # Streets 2, 5, 6 have top openings
            if row < rows - 1 and grid[row + 1][col] in (2, 5, 6):
                current_root = find(row * cols + col)
                down_root = find((row + 1) * cols + col)
                parent[current_root] = down_root
      
        # Process each cell in the grid
        for row in range(rows):
            for col in range(cols):
                street_type = grid[row][col]
              
                # Connect neighbors based on street type
                if street_type == 1:  # Horizontal street
                    connect_left(row, col)
                    connect_right(row, col)
                elif street_type == 2:  # Vertical street
                    connect_up(row, col)
                    connect_down(row, col)
                elif street_type == 3:  # Left-down corner
                    connect_left(row, col)
                    connect_down(row, col)
                elif street_type == 4:  # Right-down corner
                    connect_right(row, col)
                    connect_down(row, col)
                elif street_type == 5:  # Left-up corner
                    connect_left(row, col)
                    connect_up(row, col)
                else:  # street_type == 6, Right-up corner
                    connect_right(row, col)
                    connect_up(row, col)
      
        # Check if start (0,0) and end (m-1,n-1) are connected
        start_root = find(0)
        end_root = find(rows * cols - 1)
        return start_root == end_root
