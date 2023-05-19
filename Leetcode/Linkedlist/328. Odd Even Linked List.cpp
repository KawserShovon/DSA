class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        int cnt = 1;
        ListNode *odd , *even;
        ListNode* curr = head;
 
        odd = head;
        even = head->next;

        ListNode* odd_ = head;
        ListNode* even_ = head->next;

        curr = head->next->next;

        while(curr != nullptr)
        {
            if(cnt&1)
            {
                odd->next = curr;
                odd = odd->next;
             
            }
            else 
            {
                even->next = curr;
                even = even->next;
             
            }
            cnt++;
            curr = curr->next;
        }
        if(cnt&1)
        {
            odd->next = curr;
        }
        else 
        {
            even->next = curr;
        }

        head = odd_;
        odd->next = even_;
        return head;
    }
};