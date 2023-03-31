/* CODECHEF.com
Faizal is very sad after finding out that he is responsible for Sardar's death. He tries to drown his sorrows in alcohol and gets very drunk. Now he wants to return home but is unable to walk straight. For every 33 steps forward, he ends up walking one step backward.

Formally, in the 1st1st second he moves 33 steps forward, in the 2nd2nd second he moves 11 step backwards, in the 3rd3rd second he moves 33 steps forward, in 4th4th second 11 step backwards, and so on.

How far from his initial position will Faizal be after kk seconds have passed? Assume that Faizal's initial position is 00.

Input Format
The first line of input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains a single integer kk, the number of seconds after which Faizal's position is to be calculated.
Output Format
For each test case, output a single line containing one integer - Faizal's position after kk seconds.
Constraints
1≤T≤1000001≤T≤100000
0≤k≤1000000≤k≤100000
The sum of kk over all test cases does not exceed 10000001000000
Sample Input 1 
3
5
11
23
Sample Output 1 
7
13
25
Explanation
1st Test Case

Faizal walks 33 steps forward in the 1st1st second, ending up at 33
Faizal walks 11 step backward in the 2nd2nd second, ending up at 22
Faizal walks 33 steps forward in the 3rd3rd second, ending up at 55
Faizal walks 11 step backward in the 4th4th second, ending up at 44
Faizal walks 33 steps forward in the 5th5th second, ending up at 7
*/

#include <iostream>
using namespace std;

int main() {
	int t, k;
	cin >> t;
	
	while(t--)
	{
        cin >> k;
        int x = 0;
        
        for(int i = 1; i <= k; i++)
        {
            if(i % 2 != 0)
            {
                x += 3;
            }
            else
            {
                x -= 1;
            }
        }
        cout << x << endl;
	}
	return 0;
}
