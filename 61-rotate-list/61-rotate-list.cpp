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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
        {
            return head;
        }
        
        int len=1; 
        ListNode *tail=head, *newHead=head;
        
        while(tail->next)
        {
            len++;
            tail = tail->next;
        }
        
        tail->next = head;
        
        k = k%len;
        k = len - k;
        
        for(int i=1; i<=k; i++)
        {
            tail = tail->next;
        }
        
        newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};