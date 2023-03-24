/* CODECHEF.com
Chef prepared a problem. The admin has rated this problem for xx points.

A problem is called :

1) Easy if 1≤x<1001≤x<100

2) Medium if 100≤x<200100≤x<200

3) Hard if 200≤x≤300200≤x≤300

Find the category to which Chef’s problem belongs.

Input Format
The first line contains TT denoting the number of test cases. Then the test cases follow.
The first and only line of each test case contains a single integer xx.
Output Format
For each test case, output in a single line the category of Chef's problem, i.e whether it is an Easy, Medium or Hard problem. The output is case sensitive.

Constraints
1≤T≤501≤T≤50
1≤x≤3001≤x≤300
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
3
50
172
201
Sample Output 1 
Easy
Medium
Hard
Explanation
Test case 11: The problem with rating x=50x=50 is an easy problem as 1≤50<1001≤50<100.

Test case 22: The problem with rating x=172x=172 is a medium problem as 100≤172<200100≤172<200.

Test case 33: The problem with rating x=201x=201 is a hard problem as 200≤201≤300200≤201≤300.
*/

#include <iostream>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	
	while(t--){
        cin >> x;
        
        if(x < 100)
        {
            cout << "EASY" << endl;
        }
        else if(x < 200)
        {
            cout << "MEDIUM" << endl;	    
        }
        else
        {
            cout << "HARD" << endl;
        }
	}
	return 0;
}
