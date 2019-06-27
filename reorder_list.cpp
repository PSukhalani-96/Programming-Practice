/*
	Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln,
	reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2→…

	You may not modify the values in the list's nodes, only nodes itself may be changed.

	Example 1:
		Given 1->2->3->4, reorder it to 1->4->2->3.
	
	Example 2:
		Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    
    ListNode *reverse(ListNode *head) {
        
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode *prev = nullptr, *next = nullptr;
        ListNode *temp = head;
        
        while ( temp ) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        if ( head == nullptr || head->next == nullptr || head->next->next == nullptr )
            return;
        
        ListNode *mid  = head;
        ListNode *temp = head;

        while ( temp && temp->next ) {
            mid  = mid->next;
            temp = temp->next->next;
        }
        
        ListNode *l1 = head->next;
        ListNode *l2 = reverse(mid->next);
        ListNode *l3 = head;
        head = l3;
        
        mid->next = NULL;
        
        while ( l1 || l2 ) {
            if ( l2 ) {
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
            }
            
            if ( l1 ) {
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
            }
        }
    }
};
