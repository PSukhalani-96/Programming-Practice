/*
	Given a linked list, determine if it has a cycle in it.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyyd Cycle Detection

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if ( !head || !head->next )
            return false;
        
        ListNode *slow, *fast;
        slow = fast = head;
        
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        
        return false;
    }
};
