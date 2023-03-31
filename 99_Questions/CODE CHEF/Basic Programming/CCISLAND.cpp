/* CODECHEF.com
Suppose Chef is stuck on an island and currently he has xx units of food supply and yy units of water supply in total that he could collect from the island. He needs xrxr units of food supply and yryr units of water supply per day at the minimal to have sufficient energy to build a boat from the woods and also to live for another day. Assuming it takes exactly DD days to build the boat and reach the shore, tell whether Chef has the sufficient amount of supplies to be able to reach the shore by building the boat?

Input:
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, five integers x,y,xr,yr,Dx,y,xr,yr,D.
Output:
For each testcase, output in a single line answer "YES" if Chef can reach the shore by building the boat and "NO" if not (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤3001≤T≤300
1≤x,y≤1001≤x,y≤100
1≤xr,yr,D≤101≤xr,yr,D≤10
Sample Input
3
4 2 1 1 1
4 2 1 3 1
4 2 4 2 2
Sample Output:
YES
NO
NO
Explanation:
TestCase 1: Chef's food supply will last for 41=441=4 days and water supply will last for 21=221=2 days, so in total he will be able to survive for min(4,2)=2min(4,2)=2 days and since required time to reach the shore is 11 day, he will be able to reach there.

TestCase 2: Chef's food supply will last for 41=441=4 days and water supply will last for 23=0.6723=0.67 days, so in total he will be able to survive for min(4,0.67)=0.67min(4,0.67)=0.67 days and since required time to reach the shore is 11 day, he won't be able to reach there.

TestCase 3: Chef's food supply will last for 44=144=1 day and water supply will also last for 22=122=1 day, so in total he will be able to survive for min(1,1)=1min(1,1)=1 day and since required time to reach the shore is 22 days, he won't be able to reach there.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x1, x2, y1, y2, d;
	cin >> t;
	
	while(t--)
	{
        cin >> x1 >> y1 >> x2 >> y2 >> d;
        
        int x = x1/x2;
        int y = y1/y2;
        
        int total = min(x, y);
        if(total < d)
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
