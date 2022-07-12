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
    ListNode* reverseKGroup(ListNode* head, int k) {

   if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* temp = head;
        for(int i=0;i<k;i++)
        {
            if(temp == NULL)
            {
                return head;
            }
            temp = temp -> next;
        }
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        int cnt = 0;
        
        while(cnt < k && current != NULL)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
            cnt++;
        }
        
        if(next != NULL)
        {
            head -> next = reverseKGroup(next,k);
        }
        
        return prev;
    }
};