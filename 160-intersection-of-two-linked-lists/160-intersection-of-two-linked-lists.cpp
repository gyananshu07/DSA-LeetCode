/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //solution is to break in two part:
//         1. Equate the pointer at same posi using diff in len
        ListNode *head1 = headA, *head2 = headB;
        int l1=0, l2=0;
        
        while(head1)
        {
            l1++;
            head1 = head1->next;
        }
        
        while(head2)
        {
            l2++;
            head2 = head2->next;
        }
        
        int len = abs(l1-l2);
        ListNode *ptr1= headA, *ptr2 = headB;
        
        while(len--)
        {
            if(l1>l2)
            {
                ptr1 = ptr1->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        
//          2. Run both pointer until equal when equal return any one else they do not intersect and null will be returned
        
        while(ptr1!=ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }
};