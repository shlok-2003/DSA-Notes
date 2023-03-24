/* CODECHEF.com
Salmon has some hidden numbers that he wants you to find!

Given an integer NN, find and output any two integers A and B such that:

1≤A,B≤1091≤A,B≤109, and
A∗B=NA∗B=N.
Input:
The first line of input consists of a single integer TT (1≤T≤1051≤T≤105) -- the number of testcases.

The next TT lines will consist of one integer, NN (1≤N≤1091≤N≤109).

Output:
For each of the TT testcases, output two space-separated integers AA and BB.

Subtasks
Subtask 1 [100 points]: No additional constraints.
Sample Input 1 
5
1
3
5
8
10
Sample Output 1 
1 1
1 3
1 5
1 8
2 5
*/

#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	
	while(t--)
	{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            if(n % i == 0)
            {
                cout << i << " " << n / i << endl;
                break;
            }
        }
	}
	return 0;
}
