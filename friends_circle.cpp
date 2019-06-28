/*
	There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. 
	For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. 
	And we defined a friend circle is a group of students who are direct or indirect friends.

	Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, 
	then the ith and jth students are direct friends with each other, otherwise not. 
	
	And you have to output the total number of friend circles among all the students.

	Example 1:
		Input: 
			[[1,1,0],
		 	[1,1,0],
			[0,0,1]]
		Output: 2
		Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
		The 2nd student himself is in a friend circle. So return 2.
	
	Example 2:
		Input: 
			[[1,1,0],
	 		[1,1,1],
	 		[0,1,1]]
			Output: 1
			Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
			so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
*/

class Solution {
public:
    
    int find(int X, vector<int> parent) {
        return parent[X] == X ? X : find(parent[X], parent);
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int N = M.size();
        int groups = N;
        
        vector<int> friends(N,0);
        
        for ( int i=0; i<N; i++)
            friends[i] = i;
        
        for ( int i=0; i<N-1; i++ ) {
            for ( int j=i+1; j<N; j++) {
                if ( M[i][j] ) {
                    
                    int grp1 = find(i, friends);
                    int grp2 = find(j, friends);
                    
                    if ( grp1 != grp2 ) {
                        friends[grp1] = grp2;
                        groups--;   
                    }
                }
            }
        }
        return  groups;
        
    }
};
