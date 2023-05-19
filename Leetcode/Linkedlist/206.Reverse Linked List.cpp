class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* newTail = head;
        ListNode* prev = curr;
        ListNode* temp = curr;
        curr = curr->next;
  
        
        while(curr->next != nullptr)
        {
            
            temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;



        }
   
        head = curr;
        head->next = prev;
        newTail->next  = nullptr;
        return head;
    }
};