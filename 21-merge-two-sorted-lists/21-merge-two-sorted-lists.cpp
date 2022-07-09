/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = new ListNode(0);
        ListNode* dummy = newHead;
        ListNode *l1 = list1, *l2 = list2;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val >= l2->val)
            {
                dummy->next = l2;
                l2=l2->next;
            }
            
            else if(l1->val <= l2->val)
            {
                dummy->next = l1;
                l1=l1->next;
            }
            
            dummy = dummy->next;
        }
        
        if(l1!=NULL)
        {
            dummy->next = l1;
        }
        
        if(l2!=NULL)
        {
            dummy->next = l2;
        }
        
        return newHead->next;
    }
};