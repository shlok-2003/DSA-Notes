/* CHEFCODE.com
After a very long time, the Chef has a vacation. Chef has planned for two trips during this vacation - one with his family and the other with his friends. The family trip will take XX days and the trip with friends will take YY days. Currently, the dates are not decided but the vacation will last only for ZZ days.

Chef can be in at most one trip at any time and once a trip is started, Chef must complete it before the vacation ends. Will Chef be able to go on both these trips if he chooses the dates optimally?

Input Format
The first line will contain a single integer TT denoting the number of test cases. The description of the test cases follows.
Each test case consists of a single line of input, which contains three space-separated integers X,YX,Y and ZZ.
Output Format
For each test case, output in a single line the answer: "YES" if Chef can go on both the trips and "NO" if not.

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10001≤T≤1000
1≤X,Y,Z≤10001≤X,Y,Z≤1000
Sample Input 1 
2
1 2 4
2 2 3
Sample Output 1 
YES
NO
Explanation
Test case 11: Chef can go to the family trip on day 11 and the friends trip on days 22 and 33.

Alternatively, Chef can also plan the trip with friends on days 11 and 22 and the family trip on day 44.

Test case 22: Chef cannot plan both trips within 33 days.
*/

#include <iostream>
using namespace std;

int main() {
	int t, x, y, z;
	cin >> t;
	
	while(t--)
	{
        cin >> x >> y >> z;
        
        int td = x + y;
        
        if(td > z)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
	}
	return 0;
}
