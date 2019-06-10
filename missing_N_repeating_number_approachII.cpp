/*
	You are given a read only array of n integers from 1 to n.
	Each integer appears exactly once except A which appears twice and B which is missing.
	Return A and B.

	Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
	Note that in your output A should precede B.

	Example:
		Input:[3 1 2 5 3] 
		Output:[3, 4] 

	A = 3, B = 4
*/

typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {

    ll n = A.size();
    ll sum = 0;
    ll sq_sum = 0;
    
    ll original_sum = n*(n+1) / 2;
    ll original_sq_sum = n*(n+1)*(2*n + 1) / 6;
    
    for ( int i=0; i<n; i++) {
        sum += (ll)A[i];
        sq_sum += ((ll)A[i] * (ll)A[i]);
    }
    
    ll diff1 = sum - original_sum;
    ll diff2 = sq_sum - original_sq_sum;
    
    ll diff = diff2 / diff1;
    
    int repeated = (diff + diff1)/2;
    int missing  = (diff - diff1)/2;
    
    return {repeated, missing};
    
}
