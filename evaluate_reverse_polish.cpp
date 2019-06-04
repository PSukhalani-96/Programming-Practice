/*
	Evaluate the value of an arithmetic expression in Reverse Polish Notation.

	Valid operators are +, -, *, /. Each operand may be an integer or another expression.
	
	Note:
		Division between two integers should truncate toward zero.
		The given RPN expression is always valid. That means the expression would always evaluate to a result and 
		there won't be any divide by zero operation.
	
	Example 1:
		Input: ["2", "1", "+", "3", "*"]
		Output: 9
		Explanation: ((2 + 1) * 3) = 9
	
	Example 2:
		Input: ["4", "13", "5", "/", "+"]
		Output: 6
		Explanation: (4 + (13 / 5)) = 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
		stack<int> s;
        int i = 0;
        while ( i<tokens.size() ) {
            
            if ( tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();
                if ( tokens[i] == "+" )
                    s.push(t1+t2);
                
                else if ( tokens[i] == "-")
                    s.push(t2-t1);
                
                else if ( tokens[i] == "/" )
                    s.push(t2/t1);
                
                else
                    s.push(t1*t2);
            }
            else
                s.push(stoi(tokens[i]));
            i++;
        } 
        return s.top();
    }
};
