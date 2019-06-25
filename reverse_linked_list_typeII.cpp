/*
	Reverse a linked list from position m to n. Do it in one-pass.
	Note: 1 ≤ m ≤ n ≤ length of list.

	Example:
		Input: 1->2->3->4->5->NULL, m = 2, n = 4
		Output: 1->4->3->2->5->NULL
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
    
    ListNode *reverse(ListNode *head, int n ) {
        
        ListNode *temp = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        int count = 0;
        
        while ( temp && count <= n ) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        
        if ( prev )
            cout << prev->val << " ";
        
        if ( next ) {
            ListNode *tmp = prev;
            while ( tmp->next )
                tmp = tmp->next;
        
            tmp->next = next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *temp = head;
        
        int k = m-2;
        
        if ( k < 0 )
            return reverse(head, n-m);
        
        while ( temp && k) {
            temp = temp->next;
            k--;
        }
        
        ListNode *tmp = temp->next;
        temp->next = reverse(tmp, n-m);
        
        return head;
    }
};
