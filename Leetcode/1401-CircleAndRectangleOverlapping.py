class Solution:
    def checkOverlap(
        self,
        radius: int,
        xCenter: int,
        yCenter: int,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        
      
        def get_closest_distance_to_range(range_start: int, range_end: int, point: int) -> int:
            
            if range_start <= point <= range_end:
                # Point is within the range
                return 0
          
            if point < range_start:
                # Point is to the left/below the range
                return range_start - point
            else:
                # Point is to the right/above the range
                return point - range_end
      
        # Calculate the closest horizontal distance from circle center to rectangle
        horizontal_distance = get_closest_distance_to_range(x1, x2, xCenter)
      
        # Calculate the closest vertical distance from circle center to rectangle
        vertical_distance = get_closest_distance_to_range(y1, y2, yCenter)
      
        # Check if the squared distance is within the squared radius
        # Using squared values to avoid floating point operations
        squared_distance = horizontal_distance ** 2 + vertical_distance ** 2
        squared_radius = radius ** 2
      
        return squared_distance <= squared_radius
