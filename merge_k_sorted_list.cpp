/*
	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

	Example:

		Input:
			[
	  			1->4->5,
	  			1->3->4,
	  			2->6
			]
	
		Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int size = lists.size();
        map<int, int> m;
        
        for ( int i=0; i<size; i++) {
            
            ListNode *head = lists[i];
            while( head ) {
                
                if ( m.find(head->val) == m.end())
                    m.insert({head->val, 1});
                
                else {
                    
                    auto itr = m.find(head->val);
                    (*itr).second = (*itr).second + 1;
                }
                head = head->next;
            }
        }
        
        ListNode *l3 = new ListNode(INT_MIN);
        ListNode *temp = l3;
        
        for ( auto itr = m.begin(); itr != m.end(); itr++ ) {
            
            while( (*itr).second ) {
                temp->next = new ListNode((*itr).first);
                (*itr).second = (*itr).second - 1;
                temp = temp->next;
            }
        }
        temp->next = NULL;
        m.clear();
        return l3->next;
    }
};
