/*
	You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Follow up:
	What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

	Example:

	Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 8 -> 0 -> 7
	
	--------------------------------------------------------------------------------------------------
	Time Complexity : O(N)
	Space Complexity: O(N)
	--------------------------------------------------------------------------------------------------
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
      private:
        ListNode* head;
    
    public:
    
    void addFirst(int val) {
        ListNode* temp = new ListNode(val);
        if ( head == NULL )
            head = temp;
        else {
            temp->next = head;
            head = temp;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> s1,s2;
        while ( l1 ) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while ( l2 ) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0;
        int sum = 0;
        
        while ( !s1.empty() || !s2.empty() ) {
            
            if ( s1.empty() ) {
                sum = s2.top() + carry;
                s2.pop();
            }
            
            else if ( s2.empty() ) {
                sum = s1.top() + carry;
                s1.pop();
            }
            
            else {
                sum = s1.top() + s2.top() + carry;
                s1.pop();
                s2.pop();
            }
            
            addFirst(sum%10);
            carry = sum / 10;
            
        }
        
        if ( carry )
            addFirst(carry);
        
        return head;
    }
};
