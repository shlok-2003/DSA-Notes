/* CODECHEF.com
Six friends go on a trip and are looking for accommodation. After looking for hours, they find a hotel which offers two types of rooms — double rooms and triple rooms. A double room costs Rs. XX, while a triple room costs Rs. YY.

The friends can either get three double rooms or get two triple rooms. Find the minimum amount they will have to pay to accommodate all six of them.

Input Format
The first line contains a single integer TT - the number of test cases. Then the test cases follow.
The first and only line of each test case contains two integers XX and YY - the cost of a double room and the cost of a triple room.
Output Format
For each testcase, output the minimum amount required to accommodate all the six friends.

Constraints
1≤T≤1001≤T≤100
1≤X<Y≤1001≤X<Y≤100
Sample Input 1 
3
10 15
6 8
4 8
Sample Output 1 
30
16
12
Explanation
Test case 1: The friends can take three double rooms and thus pay a total of Rs. 3030.

Test case 2: The friends can take two triple rooms and thus pay a total of Rs. 1616.

Test case 3: The friends can take three double rooms and thus pay a total of Rs. 1212.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	
    while(t--)
    {
        cin >> x >> y;
        x = x * 3;
        y = y * 2;
        
        cout << min(x, y) << endl;
	}
	return 0;
}
