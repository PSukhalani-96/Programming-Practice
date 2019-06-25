/*
	Given a linked list, swap every two adjacent nodes and return its head.
	You may not modify the values in the list's nodes, only nodes itself may be changed.
	
	Example:
		Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode *a = head;
        ListNode *b = head->next;
        head = b;
        ListNode *c = nullptr;

        while ( a && b ) {
            a->next = b->next ? b->next : nullptr;
            b->next = a;
            if ( c )
                c->next = b;
            c = a;
            a = a->next ? a->next : nullptr;
            b = a && a->next ? a->next : nullptr;
        }
        return head;
    }
};
