/*
	Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or 
	last cell (30th cell) from source (1st cell).
	
	Input:
		The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
		Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes 
		present. 
		Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes 
		to a position 'b'.

	Output:
		For each test case in a new line print the required answer denoting the min no of dice throws.

	Constraints:
		1 <= T <= 100
		1 <= N <= 10
		1 <= a <= 30
		1 <= b <= 30

	Example:
		Input:
			2
			6
			11 26 3 22 5 8 20 29 27 1 21 9
			1
			2 30

		Output:
			3
			1

	Explanation:
		Testcase 1: 
			For 1st throw get a 2, which contains ladder to reach 22
			For 2nd throw get a 6, which will lead to 28
			Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.
*/

int no_of_moves(int arr[]) {
    
    queue<int> q;
    int len = 0;
    if ( arr[0] == -1)
        q.push(1);
    else
        q.push(arr[0]+1);
    
    while (!q.empty()) {
        int size = q.size();
        for ( int i=0; i<size; i++) {
            int tmp = q.front();
            q.pop();
            if ( tmp == 30 )
                return len;
            tmp -= 1;
            
                
            for ( int j=tmp+1; j<=tmp+6; j++) {
                
                if ( j >= 30 )
                    break;
                    
                if ( arr[j] == -1 )
                    q.push(j+1);
                else
                    q.push(arr[j]+1);
            }
        }
        len++;
    }
    
    return -1;
}

int main() {
	//code
	int t;
	cin >> t;
	
	while (t--) {
	    int arr[30];
        for ( int i=0; i<30; i++)
	        arr[i] = -1;
	   
	    int N;
	    cin >> N;
	    
	    for ( int i=0; i<N; i++) {
	        int a,b;
	        cin >> a >> b;
	        arr[a-1] = b-1;
	    }
	    
	    cout << no_of_moves(arr) << endl;
	}
	return 0;
}
