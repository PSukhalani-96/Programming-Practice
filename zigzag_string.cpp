/*
	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display 
	this pattern in a fixed font for better legibility)

	P.......A........H.......N
	..A..P....L....S....I...I....G
	....Y.........I........R
	
	And then read line by line: PAHNAPLSIIGYIR
	
	Write the code that will take a string and make this conversion given a number of rows:
		string convert(string text, int nRows);
		convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
	
	**Example 2 : **
		ABCD, 2 can be written as

		A....C
		...B....D
		and hence the answer would be ACBD.
*/

string Solution::convert(string A, int B) {
    
    if ( B <= 1)
        return A;
        
    string *str = new string[B];
    int row = 0;
    int increment = 1;
    for ( int i=0; i<A.length(); i++) {
        
        str[row].push_back(A[i]);
        
        if ( row == 0)
            increment = 1;
        else if ( row == B-1 )
            increment = -1;
        row = row + increment;
    }
    
    string res = "";
    for ( int i=0; i<B; i++) {
        res.append(str[i]);
    }
    
    return res;
}
