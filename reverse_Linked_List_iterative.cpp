/*
	Reverse a singly linked list.

	Example:

	Input: 1->2->3->4->5->NULL
	Output: 5->4->3->2->1->NULL
*/

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *temp;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        temp = head;
        
        while ( temp ) {
            
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        return prev;
        
    }
};
