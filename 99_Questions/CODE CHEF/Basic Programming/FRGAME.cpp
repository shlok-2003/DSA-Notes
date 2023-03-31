/* CODECHEF.com
Nitin and Sobhagya were playing a game with coins. If Sobhagya has more coins then he is winning, otherwise Nitin is winning. Note that this means if both Nitin and Sobhagya have the same number of coins, then Nitin is winning.

Initially Nitin has AA coins while Sobhagya has BB coins. Then Ritik came and gave his CC coins to the player who is not winning currently, after which Satyarth came and repeated the same process (gave his DD coins to the player who is not winning currently).

Find the final winner of the game.

Input Format
The first line of the input contains an integer TT - the number of test cases. The test cases then follow.
The only line of each test case contains four space-separated integers AA, BB, CC, and DD.
Output Format
For each test case, output on a single line N if Nitin is the final winner of the game, or S if Sobhagya is the final winner of the game.

Constraints
1≤T≤10001≤T≤1000
0≤A,B,C,D≤1060≤A,B,C,D≤106
Sample Input 1 
3
2 3 4 5
3 3 3 3
2 3 1 2
Sample Output 1 
S
N
S
Explanation
Test case 11:
Initially, Nitin has 22 coins and Sobhagya has 33 coins, so Sobhagya is winning.
Then, Ritik gives his 44 coins to Nitin. Now Nitin has 66 coins and Sobhagya has 33 coins, so Nitin is winning.
Then, Satyarth gives his 55 coins to Sobhagya. Finally Nitin has 66 coins and Sobhagya has 88 coins, so Sobhagya is the final winner.
Test case 22:
Initially, Nitin has 33 coins and Sobhagya has 33 coins, so Nitin is winning.
Then, Ritik gives his 33 coins to Sobhagya. Now Nitin has 33 coins and Sobhagya has 66 coins, so Sobhagya is winning.
Then, Satyarth gives his 33 coins to Nitin. Finally Nitin has 66 coins and Sobhagya has 66 coins, so Nitin is the final winner.
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b, c, d;
	cin >> t;
	
	while(t--)
	{
        cin >> a >> b >> c >> d;
        
        if(a >= b)
        {
            b += c;
        }
        else
        {
            a += c;
        }
        if(a >=b)
        {
            b += d;
        }
        else
        {
            a += d;
        }
        
        if(a >= b)
        {
            cout << "N" << endl;
        }
        else
        {
            cout << "S" << endl;
        }
	}
	return 0;
}
