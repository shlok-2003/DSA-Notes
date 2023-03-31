/* CODECHEF.com
Devendra just had a million-dollar idea and he needs funds to startup. He was recently invited to Sasta Shark Tank (A TV show where entrepreneurs pitch their ideas to investors hoping to get investment in return).

He was offered deals from two investors. The first investor offers AA dollars for 1010% of his company and the second investor offers BB dollars for 2020% of his company. Devendra will accept the offer from the investor whose valuation of the company is more. Determine which offer will Devendra accept or if both the offers are equally good.

For example, if the first investor offers 300300 dollars for 1010% of the company, then the first investor's valuation of the company is 30003000 dollars since 1010% of 3000=3003000=300. If the second investor offers 500500 dollars for 2020% of the company, then the second investor's valuation of the company is 25002500 dollars since 2020% of 2500=5002500=500.

Input Format
The first line contains a single integer TT - the number of test cases. Then the test cases follow.
The first and only line of each test case contains two integers AA and BB - the amount offered by first investor for 1010% of Devendra's company and the amount offered by second investor for 2020% of Devendra's company respectively.
Output Format
For each test case, Output FIRST if Devendra should accept the first investor's deal, output SECOND if he should accept the second investor's deal, otherwise output ANY if both deals are equally good.

You may print each character of the strings in uppercase or lowercase (for example, the strings "FiRst", "First", "FIRST", and "FIrst" will all be treated as identical).

Constraints
1≤T≤1001≤T≤100
100≤A,B≤10000100≤A,B≤10000
AA and BB are multiples of 100100
Sample Input 1 
3
100 200
200 100
200 500
Sample Output 1 
ANY
FIRST
SECOND
Explanation
Test case 1: First investor's valuation of Devendra's company was 10001000 since 1010% of 1000=1001000=100 which is the amount he offered for 1010% of the company.

Second investor's valuation of Devendra's company was also 10001000 since 2020% of 1000=2001000=200 which is the amount he offered for 2020% of the company.

Therefore he can accept any of the deal.

Test case 2: First investor offered a better deal as he valued Devendra's company at 20002000 dollars (since 1010% of 2000=2002000=200) compared to the second investor who valued Devendra's company at 500500 dollars (since 2020% of 500=100500=100).

Test case 3: Second investor offered a better deal as he valued Devendra's company at 25002500 dollars compared to the first investor who valued Devendra's company 20002000 dollars.
*/

#include <iostream>
using namespace std;

int main() {
	int t; 
	float a, b;
	cin >> t;
	
	while(t--)
	{
        cin >> a >> b;
        
        a = a / 0.1;
        b = b / 0.2;
        
        if(a > b)
        {
            cout << "FIRST" << endl;
        }
        else if(a < b)
        {
            cout << "SECOND" << endl;
        }
        else
        {
            cout << "ANY" << endl;
        }
	}
    
	return 0;
}
