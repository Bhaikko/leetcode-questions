// ListNode* reverseList(ListNode* head, ListNode* &tail)
// {
//     if (head->next == nullptr) {
//         tail = head;
//         return head;
//     }    
    
//     ListNode* reversedList = reverseList(head->next, tail);
    
//     head->next = nullptr;
//     tail->next = head;
//     tail = head;
//     head = reversedList;
    
//     return head;
    
// }