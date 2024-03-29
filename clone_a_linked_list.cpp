/*
	A linked list is given such that each node contains an additional random pointer which could point to any node in the 
	list or null.
	
	Example 1:
		Input:	{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
		Explanation:
			Node 1's value is 1, both of its next and random pointer points to Node 2.
			Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *current = head;
        Node *temp;
        
        while ( current ) {
            
            temp = current->next;
            current->next = new Node(current->val, NULL, NULL);
            current->next->next = temp;
            current = temp;
        }
        
        current = head;
        while ( current ) {
            if ( current->next )
                current->next->random = current->random ? current->random->next : current->random;
            
            current = current->next? current->next->next : current->next;
        }
        
        Node *clone = nullptr;
        current = head;
        
        if ( head )
            clone = current->next;
        temp = clone;
        
        while ( current && temp ) {
            current->next = current->next ? current->next->next: current->next;
            temp->next = temp->next ? temp->next->next: temp->next;
            current = current->next;
            temp = temp->next;
        }
        
        return clone;
        
    }
};
