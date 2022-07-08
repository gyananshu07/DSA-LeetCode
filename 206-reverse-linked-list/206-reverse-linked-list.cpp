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
    private:
    ListNode* reverse(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode* newHead = reverse(head->next);
        ListNode* headNext = head->next;
        headNext->next = head;
        head->next = nullptr;
        
        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};