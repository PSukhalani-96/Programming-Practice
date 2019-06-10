/*
	Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

	Input is guaranteed to be within the range from 1 to 3999.

	Example :
		Input : 5
		Return : "V"
	
		Input : 14
		Return : "XIV"
*/

string Solution::intToRoman(int num) {
    
    string roman = "";
    string ONES[]  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string TENS[]  = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string HUNDS[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string THNSD[] = {"", "M", "MM", "MMM"};
        
    roman = THNSD[(num/1000)%10] + HUNDS[(num/100)%10] + TENS[(num/10)%10] + ONES[num%10]; 
        
    return roman;
}
