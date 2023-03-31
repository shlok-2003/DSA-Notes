/* CODECHEF.com
Chefland is holding a virtual marathon for the categories 1010 km, 2121 km and 4242 km having prizes A,B,CA,B,C (A<B<CA<B<C) respectively to promote physical fitness. In order to claim the prize in a particular category the person must cover the total distance for that category within DD days. Also a single person cannot apply in multiple categories.

Given the maximum distance dd km that Chef can cover in a single day, find the maximum prize that Chef can win at the end of DD days. If Chef can't win any prize, print 00.

Input
The first line contains an integer TT, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, five integers D,d,A,B,CD,d,A,B,C.
Output
For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤501≤T≤50
1≤D≤101≤D≤10
1≤d≤51≤d≤5
1≤A<B<C≤1051≤A<B<C≤105
Sample Input 1 
3
1 1 1 2 3
10 1 1 2 3
10 3 1 2 3
Sample Output 1 
0
1
2
Explanation
Test Case 11: The maximum distance covered by Chef is 1⋅1=11⋅1=1 km which is less than any of the available distance categories. Hence Chef won't be able to claim a prize in any of the categories.

Test Case 22: The maximum distance covered by Chef is 10⋅1=1010⋅1=10 km which is equal to distance of the first category. Hence Chef can claim the maximum prize of 11 units.

Test Case 33: The maximum distance covered by Chef is 10⋅3=3010⋅3=30 km which is more than the distance of the second category but less than that of the third category. Hence Chef can claim the maximum prize of 22 units.
*/

#include <iostream>
using namespace std;

int main() {
	int t, td, d, a, b, c;
	cin >> t;
	
	while(t--)
	{
        cin >> td >> d >> a >> b >> c;
        
        td = td * d;
        if(td >= 10 && td < 21)
        {
            cout << a << endl;
        }
        else if(td >= 21 & td < 42)
        {
            cout << b << endl;
        }
        else if(td >=42)
        {
            cout << c << endl;    
        }
        else
        {
            cout << "0" << endl;  
        }
	}
	return 0;
}
