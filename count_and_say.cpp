/*
	The count-and-say sequence is the sequence of integers with the first five terms as following:

	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.

	Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
	
	Example 1:
		Input: 1
		Output: "1"
	
	Example 2:
		Input: 4
		Output: "1211"

*/

class Solution {
public:
    string countAndSay(int n) {
     
        string num = "1";
        string res = "";
        
        for ( int i=1; i<n; i++) {
            
            int count = 1;
            
            for ( int j = 0; j < num.length(); j++) {
                char temp = num[j];
                if ( j+1 < num.length() && num[j] == num[j+1] )
                    count++;
                else {
                    res = res + std::to_string(count) + temp;
                    count = 1;
                }
            }
            
            num = res;
            res = "";
        }
            
        return num;
    }
};
