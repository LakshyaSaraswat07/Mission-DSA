class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node pointing to head to handle edge cases
        dummy_node = ListNode(next=head)
      
        # Initialize two pointers for the two-pointer technique
        # slow_ptr will eventually point to the node before the middle
        slow_ptr = dummy_node
        fast_ptr = head
      
        # Move fast_ptr twice as fast as slow_ptr
        # When fast_ptr reaches the end, slow_ptr will be before the middle
        while fast_ptr and fast_ptr.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
      
        # Delete the middle node by skipping it
        slow_ptr.next = slow_ptr.next.next
      
        # Return the head of the modified list
        return dummy_node.next
