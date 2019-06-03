/*
	Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
    ListNode *detectCycle(ListNode *head) {
        
        if ( !head || !head->next )
            return NULL;
        
        ListNode *slow, *fast;
        slow = fast = head;
        
        while (slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        if ( slow == fast  ){
            
            fast = head;
            while(fast) {
                if ( fast == slow )
                    return fast;
                fast = fast->next;
                slow = slow->next;
            }
            
        }
        return NULL;
    }
};