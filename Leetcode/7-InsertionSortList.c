struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Already sorted or empty list
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0; // Dummy node to simplify insertions at the beginning
    dummy->next = NULL;

    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next_node = current->next; // Store the next node to process

        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < current->val) {
            prev = prev->next; // Find the correct insertion point
        }

       
        current->next = prev->next;
        prev->next = current;

        current = next_node; 
    }

    return dummy->next; 
}
