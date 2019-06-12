/*
	Given a list of non negative integers, arrange them such that they form the largest number.
	
	For example:
		Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

static bool comp(string s1, string s2) {
        
    string val1 = s1 + s2;
    string val2 = s2 + s1;
    return val1 > val2;
}

string Solution::largestNumber(const vector<int> &nums) {
    
    vector<string> str(nums.size());
    int j=0; 
        
    while ( j < nums.size() && nums[j] == 0)
        j++;

    if ( j == nums.size())
        return "0";     
        
    for ( int i=j; i<nums.size(); i++)
        str[i-j] = std::to_string(nums[i]);
        
    sort(str.begin(), str.end(), comp);
    string res = "";
        
    for (int i=0; i<str.size(); i++)
        res = res + str[i];
        
    for (int i=0; i<j; i++)
        res = res + '0';
        
    return res;
}
