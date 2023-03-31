/* CodeChef.com
There are 33 problems in a contest namely A,B,CA,B,C respectively. Alice bets Bob that problem CC is the hardest while Bob says that problem BB will be the hardest.

You are given three integers SA,SB,SCSA,SB,SC which denotes the number of successful submissions of the problems A,B,CA,B,C respectively. It is guaranteed that each problem has a different number of submissions. Determine who wins the bet.

1) If Alice wins the bet (i.e. problem CC is the hardest), then output AliceAlice.

2) If Bob wins the bet (i.e. problem BB is the hardest), then output BobBob.

3) If no one wins the bet (i.e. problem AA is the hardest), then output DrawDraw.

Note: The hardest problem is the problem with the least number of successful submissions.

Input Format
The first line of input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains three space-separated integers SA,SB,SCSA,SB,SC, denoting the number of successful submissions of problems A,B,CA,B,C respectively.
Output Format
For each test case, output the winner of the bet or print Draw in case no one wins the bet.

Constraints
1≤T≤1001≤T≤100
1≤SA,SB,SC≤1001≤SA,SB,SC≤100
SA,SB,SCSA,SB,SC are all distinct.
Sample Input 1 
3
1 4 2
16 8 10
14 15 9
Sample Output 1 
Draw
Bob
Alice
Explanation
Test case 11: Problem AA turns out to be the hardest so no one wins the bet.

Test case 22: Problem BB turns out to be the hardest so Bob wins the bet.

Test case 33: Problem CC turns out to be the hardest so Alice wins the bet.
*/
#include <iostream>
using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	
	while(t--){
        cin >> a >> b >> c;
        
        int s = min(a, min(b, c));
        
        if(s == a)
        {
            cout << "DRAW" << endl;
        }
        if(s == b)
        {
            cout << "BOB" << endl;
        }
        if(s == c)
        {
            cout << "ALICE" << endl;
        }
	}

	return 0;
}
