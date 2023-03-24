/* CODECHEF.com
Chef is currently facing the north direction. Each second he rotates exactly 9090 degrees in clockwise direction. Find the direction in which Chef is facing after exactly XX seconds.

Note:Note: There are only 4 directions: North, East, South, West (in clockwise order).

Input Format
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains of a single integer XX.
Output Format
For each testcase, output the direction in which Chef is facing after exactly XX seconds.

Constraints
1≤T≤1001≤T≤100
1≤X≤10001≤X≤1000
Sample Input 1 
3
1
3
6
Sample Output 1 
East
West
South
Explanation
Chef is facing North in the starting.

Test Case 11: After 11 second he turns 9090 degrees clockwise and now faces the east direction.

Test Case 22: Direction after 11 second- east

Direction after 22 seconds- south

Direction after 33 seconds- west
*/

#include <iostream>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	
    while(t--)
	{
        cin >> x;
        
        if(x % 4 == 0)
        {
            cout << "North" << endl;
        }
        else if(x % 4 == 1)
        {
            cout << "East" << endl;
        }
        else if(x % 4 == 2)
        {
            cout << "South" << endl;
        }
        else if(x % 4 == 3)
        {
            cout << "West" << endl;
        }

	}
	return 0;
}
