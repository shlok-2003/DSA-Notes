/* CODECHEF.com
The current price of petrol is XX rupees, and the current price of diesel is YY rupees. At the start of each month, the price of petrol increases by AA rupees and the price of diesel increases by BB rupees.

Chef is curious to know which fuel costs less at the end of the KthKth month. If petrol is cheaper than diesel at the end of KthKth month, then print PETROLPETROL. If diesel is cheaper than petrol at the end of the KthKth month, then print DIESELDIESEL. If both the fuels have the same price at the end of the KthKth month, then print SAME PRICESAME PRICE.

Input Format
The first line of input contains a single integer TT, denoting the number of test cases. The description of TT test cases follows.
Each test case consists of a single line of input, containing five space-separated integers X,Y,A,B,KX,Y,A,B,K.
Output Format
For each test case,

Print PETROLPETROL if petrol is cheaper than diesel.
Print DIESELDIESEL if diesel is cheaper than petrol.
Print SAME PRICESAME PRICE otherwise.
Note: The output is case-insensitive. You can print each character in either lower-case or upper-case.

Constraints
1≤T≤10001≤T≤1000
1≤K≤10001≤K≤1000
0≤X,Y,A,B≤10000≤X,Y,A,B≤1000
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
3
1 1 1 1 1
2 1 2 1 2
2 2 1 1 2
Sample Output 1 
SAME PRICE
DIESEL
SAME PRICE
Explanation
Test case 1:

Initially, the price of petrol is 11 rupee and the price of diesel is 11 rupee. Since A=1A=1 and B=1B=1, the prices of both petrol and diesel increase by 11 rupee at the start of every month. So, at the start of the first month, the price of petrol becomes 1+1=21+1=2 rupees and the price of diesel becomes 1+1=21+1=2 rupees. By the end of the first month, the price of petrol and diesel are both 22 rupees and hence they both have the same price.

Test case 2:

Initially, the price of petrol is 22 rupees and the price of diesel is 11 rupee. Since A=2A=2 and B=1B=1, the price of petrol increases by 22 rupee and the price of diesel increases by 11 rupee at the start of every month. It follows that at the start of the first month, the price of petrol becomes 2+2=42+2=4 rupees and the price of diesel becomes 1+1=21+1=2 rupees. And by the start of the second month, the price of petrol becomes 4+2=64+2=6 rupees and the price of diesel becomes 2+1=32+1=3 rupees. By the end of the second month, the prices of petrol and diesel are 66 rupees and 33 rupees respectively and hence diesel is cheaper than petrol.

Test case 3:

Initially, the price of petrol is 22 rupee and the price of diesel is 22 rupee. 
Since A=1A=1 and B=1B=1, the price of petrol increases by 11 rupee and the price of diesel increases by 11 rupee at the start of every month. It follows that at the start of the first month, the price of petrol becomes 2+1=32+1=3 rupees and the price of diesel becomes 2+1=32+1=3 rupees. And by the start of the second month, the price of petrol becomes 3+1=43+1=4 rupees and the price of diesel becomes 3+1=43+1=4 rupees. 
By the end of the second month, the prices of petrol and diesel are both 44 rupees and hence both have the same prices.
*/

#include <iostream>
using namespace std;

int main() {
	int t, x, y, a, b, k;
	cin >> t;
	
	while(t--)
	{
        cin >> x >> y >> a >> b >> k;
        
        x = x + a*k;
        y = y + b*k;
        
        if(x > y)
        {
            cout << "DIESEL" << endl;
        }
        else if(x < y)
        {
            cout << "PETROL" << endl;
        }
        else
        {
            cout << "SAME PRICE" << endl;
        }
	}
	return 0;
}
