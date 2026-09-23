class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        
        if(head == NULL || l == r)
            return head;

        ListNode* temp1 = head;
        ListNode* temp2 = head;

        int i = 1;

        while(i < l) {
            temp1 = temp1->next;
            i++;
        }

        i = 1;

        while(i < r) {
            temp2 = temp2->next;
            i++;
        }

        // node after r
        ListNode* after = temp2->next;

        // reverse l to r
        ListNode* prev = after;
        ListNode* curr = temp1;

        while(curr != after) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // l == 1
        if(l == 1)
            return prev;

        // find node before l
        ListNode* before = head;
        i = 1;

        while(i < l-1) {
            before = before->next;
            i++;
        }

        before->next = prev;

        return head;
    }
};