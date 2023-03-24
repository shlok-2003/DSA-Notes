/* CODECHEF.com
Yesterday, puppy Tuzik learned a magically efficient method to find the sum of the integers from 1 to N. He denotes it as sum(N). But today, as a true explorer, he defined his own new function: sum(D, N), which means the operation sum applied D times: the first time to N, and each subsequent time to the result of the previous operation.

For example, if D = 2 and N = 3, then sum(2, 3) equals to sum(sum(3)) = sum(1 + 2 + 3) = sum(6) = 21.

Tuzik wants to calculate some values of the sum(D, N) function. Will you help him with that?

Input
The first line contains a single integer T, the number of test cases. Each test case is described by a single line containing two integers D and N.

Output
For each testcase, output one integer on a separate line.

Constraints
1 ≤ T ≤ 16
1 ≤ D, N ≤ 4
Sample Input 1 
2
1 4
2 3
Sample Output 1 
10
21
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
    
int main() {
	int t, d, n;
	cin >> t;
	
	while(t--)
	{
        cin >> d >> n;
        int x;
        
        while(d--)
        {	
            x = 0;
            for(int i = 0; i <=  n; i++)
            {
                x += i;
            }
            n = x;
        }
        cout << x << endl;
    }
	return 0;
}
