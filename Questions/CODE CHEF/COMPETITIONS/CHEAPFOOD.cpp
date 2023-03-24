/* CODECHEF.com
Chef is ordering food online (instead of cooking) and the bill comes out to be Rs. XX. Chef can use one of the following two coupons to avail a discount.

Get 1010 percent off on the bill amount
Get a flat discount of Rs. 100100 on the bill amount
What is the maximum discount Chef can avail?

Input Format
The first line contains a single integer TT - the number of test cases. Then the test cases follow.
The first and only line of each test case contains a single integer XX - the bill amount before discount.
Output Format
For each testcase, output the maximum discount Chef can avail.

Constraints
1≤T≤1001≤T≤100
100≤X≤10000100≤X≤10000
XX is a multiple of 100100.
Sample Input 1 
3
300
1300
1000
Sample Output 1 
100
130
100
Explanation
Test case 1: Using the second coupon, Chef can get a flat discount of Rs. 100100, which is maximum.

Test case 2: Using the first coupon, Chef can get a 1010 percent discount of Rs. 130130, which is maximum.

Test case 3: No matter which coupon Chef chooses Chef will get a discount of Rs. 100100.
*/

#include <iostream>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	
	while(t--)
	{
        cin >> x;
        int y = x / 10;
        if(y >= 100)
        {
            cout << y << endl;
        }
        else
        {
            cout << "100" << endl;
        }
	}
	return 0;
}
