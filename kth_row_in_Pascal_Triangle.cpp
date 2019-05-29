/*
	Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
*/


// Approach - 1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if ( rowIndex == 0)
            return {1};
        
        if ( rowIndex < 0 )
            return {};
        
        vector<int> v(rowIndex+1);
        
        v[0] = 1;
        v[1] = 1;
        
        if ( rowIndex == 1)
            return v;
        
        for ( int i=2; i<=rowIndex; i++) {
            int t1 = v[0];
            int t2 = v[1];
            
            for (int j=1; j<i; j++) {
                int t3 = t1 + t2;
                t1 = v[j];
                if ( j+1 < v.size())
                    t2 = v[j+1];
                v[j] = t3;
            }
            v[i] = 1;
        }
        return v;
    }
};
