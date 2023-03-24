/* CODECHEF.com
Chef has decided to go to a gold mine along with NN of his friends (thus, total N+1N+1 people including Chef go to the gold mine).

The gold mine contains a total of XX kg of gold. Every person has the capacity of carrying up atmostatmost YY kg of gold.

Will Chef and his friends together be able to carry up all the gold from the gold mine assuming that they can go to the mine exactly once.

Input Format
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, three integers N,X,YN,X,Y.
Output Format
For each testcase, output "YES" if you and your friends can carry all the gold, otherwise output "NO".

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10001≤T≤1000
1≤N,X,Y≤10001≤N,X,Y≤1000
Sample Input 1 
3
2 10 3
2 10 4
1 5 10
Sample Output 1 
NO
YES
YES
Explanation
Test Case 11: You along with your friends can only carry a maximum of 9(3×3)9(3×3) kg of gold.

Test Case 22: It is possible to carry all the gold from the mine. You can carry 44 kg of gold and your both friends carry 33 kg of gold each, thus carrying the whole 1010 kg of gold.
*/

#include <iostream>
using namespace std;

int main() {
	int t, n, x, y;
	cin >> t;
	
	while(t--)
	{
        cin >> n >> x >> y;
        
        n = 1 + n;
        y = n * y;      //total gold carried
        
        if(y >= x)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
	}
	return 0;
}
