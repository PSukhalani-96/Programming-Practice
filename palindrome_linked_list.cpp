/*
	Given a singly linked list, determine if it is a palindrome.

	Example 1:
		Input: 1->2
		Output: false
	
	Example 2:
		Input: 1->2->2->1
		Output: true
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
        
        if ( head == nullptr )
            return nullptr;
        
        ListNode *next, *prev = nullptr;
        ListNode *current = head;
        
        while ( current ) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if ( head == nullptr || head->next == nullptr )
            return true;
        
        ListNode *mid = head;
        ListNode *current = head;
    
        while ( current && current->next ) {
            mid = mid->next;
            current = current->next->next;
        }

        mid->next = reverse(mid->next);
        
        current = head;
        ListNode *tmp1 = mid->next;
        
        while ( tmp1 ) {
            if (current->val != tmp1->val)
                return false;
            current = current->next;
            tmp1 = tmp1->next;
        }
        
        if ( mid->val == current->val )
            return true;
        return false;
    }
};
